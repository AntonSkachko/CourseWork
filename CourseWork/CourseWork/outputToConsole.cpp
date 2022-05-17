#include "outputToConsole.h"

string EnterPassword() {
	string pass;
	char symbol;
	const char BACK_SPACE = 0;
	const char ENTER = 13;
	while (true) {
		symbol = _getch();
		if (symbol == ENTER) {
			break; 
		}
		else if (symbol == BACK_SPACE) {
			if (pass.size() > 0) {
				pass.pop_back();
				cout << "\b \b";
			}
		}
		else if (symbol > 31) {
			cout << "*";
			pass += symbol;
		}
		else {
			cout << "\b \b";
		}
	}
	cout << "\n";
	return pass;
}

string validation(Users* arrayOfUsers, int sizeArrayOfUsers) {
	int attempts = 3; // количество попыток у пользовател€
	string username, password;
	while (true) {
		system("cls");

		cout << " ¬ведите логин: "; cin >> username;
		cout << " ¬ведите пароль: ";
		password = EnterPassword();

		if (isPasswordCorrect(password, username, arrayOfUsers, sizeArrayOfUsers) &&
			isUsernameCorrect(username, arrayOfUsers, sizeArrayOfUsers)) {
			return username;
		}
		cout << " Ќеверный пароль или логин, повторыите попытку, у вас осталось попыток " << attempts;
		--attempts;
		if (attempts == 0) {
			cout << " ¬аш лимит исчерпан";
			return;
		}
	}

}


void productTableOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(2) << "день когда продук произведЄн" << setw(2) << "|"
		<< setw(2) << "номер цеха" << setw(2) << "|" << setw(2) << "название продукта" << setw(2) << "|"
		<< setw(2) << "количество выпущенных единиц" << setw(2) << "|" << "им€ ответсвенного по цеху в данный день" << setw(2) << "|\n";
	for (int i = 0; i < sizeArrayOfData; i++) {
		cout << "--------------------------------------------------------------------------------------------";
		cout << "|" << setw(2) << i << setw(2) << "|" << setw(2) << arrayOfProduct[i].dayWhenProductCreate.day << "." <<
			arrayOfProduct[i].dayWhenProductCreate.month << "." << arrayOfProduct[i].dayWhenProductCreate.year << setw(2) << "|"
			<< setw(2) << arrayOfProduct[i].workShopNumber << setw(2) << "|" << setw(2) << arrayOfProduct[i].productName << setw(2) << "|"
			<< setw(2) << arrayOfProduct[i].numberOfProductsProduced << setw(2) << "|" << arrayOfProduct[i].responsiblePerson << setw(2) << "|\n";
	}
	cout << "--------------------------------------------------------------------------------------------";
	
}


void userTableOutput(Users* arrayOfUsers, int sizeArrayOfUsers) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(2) << "им€ пользовател€" << setw(2) << "|"
		<< setw(2) << "роль" << setw(2) << "|" << setw(2) << "доступ" << setw(2) << "|\n";
	for (int i = 0; i < sizeArrayOfUsers; i++) {
		cout << "--------------------------------------------------------------------------------------------";
		cout << "|" << setw(2) << i << setw(2) << "|" << setw(2) << arrayOfUsers[i].nickname << setw(2) << "|"
			<< setw(2) << arrayOfUsers[i].role << setw(2) << "|" << setw(2) << arrayOfUsers[i].access << setw(2) << "|\n";
	}
	cout << "--------------------------------------------------------------------------------------------";
}

void adminOutput(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {

}

void userOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	productTableOutput(arrayOfProduct, sizeArrayOfData);
	cout << "\n 1) сортировка \n 2) поиск \n 3) выход";
	int choice, sortingChoice;
	cin >> choice;

	switch (choice) {
		case 1:
			/* 1 - sorting by date (int)
			   2 - sorting by workShopNumber (int)
			   3 - sorting by productName (string)
			   4 - sorting by numberOfProductsProduced (int)
			   5 - sorting by responsiblePerson (string)

			*/
			productTableOutput(arrayOfProduct, sizeArrayOfData);
			cout << " по какому методу будем соритровать:\n 1) по дню когда он был произведЄн \n"
				<< " сортировка по номеру цеха \n 3) по названию продукта \n 4) по количеству выпущенных единиц"
				<< "\n 5) по имени ответсвенного";
			sorting(arrayOfProduct, sizeArrayOfData, sortingChoice);

		case 2:
			
	}
}

void writeToConsole(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {
	setlocale(LC_ALL, "Russian");
	cout << " 1) ¬ойти \n2) —оздать новый аккаунт \n3) ¬ыйти из системы \n";

	string username;
	int choice;
	cout << " ¬ведите ваш выбор: ";
	cin >> choice;

	switch (choice) {
		case 1: 
			username = validation(arrayOfUsers, sizeArrayOfUsers);
			
			if (isItAdmin(username, arrayOfUsers, sizeArrayOfUsers)) {

				productTableOutput(arrayOfProduct, sizeArrayOfData);
			}
			else {
				if (isAccess(username, arrayOfUsers, sizeArrayOfUsers)) {
					productTableOutput(arrayOfProduct, sizeArrayOfData); 
				}
			}


	}

}
