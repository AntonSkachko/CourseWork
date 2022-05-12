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

void tableOutput(ProductInfo* arrayOfData, int sizeArrayOfData) {

}

void writeToConsole(ProductInfo* arrayOfData, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {
	setlocale(LC_ALL, "Russian");
	cout << "1) Войти \n2) Создать новый аккаунт \n3) Выйти из системы \n";

	int choice;
	cout << "Введите ваш выбор: ";
	cin >> choice;

	switch (choice) {
		case 1: 
			int attempts = 3; // количество попыток у пользователя
			string username, password;
			while (attempts) {
				system("cls");
				
				cout << "Введите логин: "; cin >> username;
				cout << "Введите пароль: ";
				password = EnterPassword();

				if (isPasswordCorrect(password, username, arrayOfUsers, sizeArrayOfUsers) &&
					isUsernameCorrect(username, arrayOfUsers, sizeArrayOfUsers)) {
					break;
				}
				cout << "Неверный пароль или логин, повторыите попытку, у вас осталось попыток " << attempts;
				--attempts;
			}

			if (isItAdmin(username, arrayOfUsers, sizeArrayOfUsers)) {

			}
			else {
				if (isAccess(username, arrayOfUsers, sizeArrayOfUsers)) {

				}
			}


	}

}
