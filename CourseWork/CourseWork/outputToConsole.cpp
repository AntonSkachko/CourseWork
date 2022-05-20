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
	int attempts = 3; // количество попыток у пользователя
	string username, password;
	while (true) {
		system("cls");

		cout << " Введите логин: "; cin >> username;
		cout << " Введите пароль: ";
		password = EnterPassword();

		if (isPasswordCorrect(password, username, arrayOfUsers, sizeArrayOfUsers) &&
			isUsernameCorrect(username, arrayOfUsers, sizeArrayOfUsers)) {
			return username;
		}
		cout << " Неверный пароль или логин, повторыите попытку, у вас осталось попыток " << attempts;
		--attempts;
		if (attempts == 0) {
			cout << " Ваш лимит исчерпан";
			break;
		}
	}

}

// вывод таблицы продуктов склада
void productTableOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(2) << "день когда продук произведён" << setw(2) << "|"
		<< setw(2) << "номер цеха" << setw(2) << "|" << setw(2) << "название продукта" << setw(2) << "|"
		<< setw(2) << "количество выпущенных единиц" << setw(2) << "|" << "имя ответсвенного по цеху в данный день" << setw(2) << "|\n";
	for (int i = 0; i < sizeArrayOfData; i++) {
		cout << "--------------------------------------------------------------------------------------------";
		cout << "|" << setw(2) << i << setw(2) << "|" << setw(2) << arrayOfProduct[i].dayWhenProductCreate.day << "." <<
			arrayOfProduct[i].dayWhenProductCreate.month << "." << arrayOfProduct[i].dayWhenProductCreate.year << setw(2) << "|"
			<< setw(2) << arrayOfProduct[i].workShopNumber << setw(2) << "|" << setw(2) << arrayOfProduct[i].productName << setw(2) << "|"
			<< setw(2) << arrayOfProduct[i].numberOfProductsProduced << setw(2) << "|" << arrayOfProduct[i].responsiblePerson << setw(2) << "|\n";
	}
	cout << "--------------------------------------------------------------------------------------------";
	
}

// вывод таблицы пользователей
void userTableOutput(Users* arrayOfUsers, int sizeArrayOfUsers) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(2) << "имя пользователя" << setw(2) << "|"
		<< setw(2) << "хешированный пароль" << setw(2) << "|"
		<< setw(2) << "роль" << setw(2) << "|" << setw(2) << "доступ" << setw(2) << "|\n";
	for (int i = 0; i < sizeArrayOfUsers; i++) {
		cout << "--------------------------------------------------------------------------------------------";
		cout << "|" << setw(2) << i << setw(2) << "|" << setw(2) << arrayOfUsers[i].nickname << setw(2) << "|"
			<< setw(2) << arrayOfUsers[i].saltedHashPassword << setw(2) << "|"
			<< setw(2) << arrayOfUsers[i].role << setw(2) << "|" << setw(2) << arrayOfUsers[i].access << setw(2) << "|\n";
	}
	cout << "--------------------------------------------------------------------------------------------";
}

void outputSorting(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	
	system("cls");
	productTableOutput(arrayOfProduct, sizeArrayOfData);
	cout << " по какому методу будем соритровать:\n 1) по году когда он был произведён \n"
		<< " сортировка по номеру цеха \n 3) по названию продукта \n 4) по количеству выпущенных единиц"
		<< "\n 5) по имени ответсвенного\n";
	int sortingChoice;
	cin >> sortingChoice;
	sorting(arrayOfProduct, sizeArrayOfData, sortingChoice);

	system("cls");
	productTableOutput(arrayOfProduct, sizeArrayOfData);
}

void outputSearch(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	system("cls");
	ProductInfo* searchingArray = new ProductInfo[1];
	string nameOfResponsible, nameOfProduct;
	int searchingChoice, date, element, count, numberOfWorkshop;
	productTableOutput(arrayOfProduct, sizeArrayOfData);
	cout << " по какому методу будем искать:\n 1) по дню когда он был произведён \n"
		<< " сортировка по номеру цеха \n 3) по названию продукта \n 4) по количеству выпущенных единиц"
		<< "\n 5) по имени ответсвенного \n";
	cin >> searchingChoice;

	system("cls");
	productTableOutput(arrayOfProduct, sizeArrayOfData);

	switch (searchingChoice) {

	case 1:
		cout << " Введите год: ";
		cin >> date;
		searchingArray = searchByDayWhenProductCreate(arrayOfProduct, sizeArrayOfData, date);
		break;

	case 2:
		cout << " Введите номер цеха: ";
		cin >> element;
		searchingArray = searchByWorkShopNumber(arrayOfProduct, sizeArrayOfData, element);
		break;

	case 3:
		cout << " Введите название продукта: ";
		cin >> nameOfProduct;
		searchingArray = searchByProductName(arrayOfProduct, sizeArrayOfData, nameOfProduct);
		break;

	case 4:
		cout << " Введите количество выпущенной продукции: ";
		cin >> count;
		searchingArray = searchByNumberOfProductsProduced(arrayOfProduct, sizeArrayOfData, count);
		break;
	case 5:
		cout << " Введите ответсвенного в день выпуска продукции: ";
		cin >> nameOfResponsible;
		searchingArray = searchByResponsiblePerson(arrayOfProduct, sizeArrayOfData, nameOfResponsible);
		break;
	default:
		cout << " такого числа нет попробуй снова";

	}
	productTableOutput(searchingArray, 1);

}

void outputIndividualTask(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	system("cls");
	Date beginning, end;
	int numberOfWorkshop;

	cout << " Введите номер цеха: ";
	cin >> numberOfWorkshop;

	cout << " Введите период времени \n начало: \n	день: ";
	cin >> beginning.day;
	cout << "	месяц: ";
	cin >> beginning.month;
	cout << "	год:";
	cin >> beginning.year;

	cout << " Введите период времени \n конец: \n	день: ";
	cin >> end.day;
	cout << "	месяц: ";
	cin >> end.month;
	cout << "	год:";
	cin >> end.year;
	system("cls");
	productTableOutput(OutputOfNumberOfManufacturedProducts(arrayOfProduct, beginning, end, numberOfWorkshop, sizeArrayOfData), 10);
}

// что должно выводить у обычного пошльзователя
void userOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	// sortingChoice и searchingChoice переменные для выбора метода сортировки и поиска соответсвенно
	
	int choice, sizeArrayOfProduct;
	string nameOfProduct, nameOfResponsible;

	while (true) {
		system("cls");
		cout << "\n 1) сортировка \n 2) поиск \n 3) вывод количество выпущенных изделий по каждому наименованию \n 4) выход\n";
		cin >> choice;
		switch (choice) {
			case 1:
				outputSorting(arrayOfProduct, sizeArrayOfData);
				break;

			case 2:
				outputSearch(arrayOfProduct, sizeArrayOfData);
				break;

			case 3:
				outputIndividualTask(arrayOfProduct, sizeArrayOfData);
				break;

			case 4:
				system("cls");
				cout << " Прощайте! ";
				return;

			default:
				system("cls");
				cout << " Введите коректное число!";
		}
	}
}

void outputWorkdWithUsers(Users* arrayOfUsers, int sizeArrayOfUsers) {
	system("cls");

	userTableOutput(arrayOfUsers, sizeArrayOfUsers);
	int choiceOfUserTable, numberOfUser;
	while (true) {
		cout << "\n 1) удаление пользователя\n 2) одобрить регестрацию \n 3) сделать человека админом \n 4) выход";
		cin >> choiceOfUserTable;
		switch (choiceOfUserTable) {
			case 1:
				system("cls");

				userTableOutput(arrayOfUsers, sizeArrayOfUsers);
				cout << " Введите номер удаляемого пользователя: ";
				cin >> numberOfUser;

				deleteUser(arrayOfUsers, sizeArrayOfUsers, numberOfUser);
				break;

			case 2:
				system("cls");

				userTableOutput(arrayOfUsers, sizeArrayOfUsers);
				cout << " Введите номер одобряемого пользователя: ";
				cin >> numberOfUser;

				approveUser(arrayOfUsers, sizeArrayOfUsers, numberOfUser);
				break;

			case 3:
				system("cls");

				userTableOutput(arrayOfUsers, sizeArrayOfUsers);
				cout << " Введите номер человека, который станет тоже админом: ";
				cin >> numberOfUser;

				makeUserAdmin(arrayOfUsers, sizeArrayOfUsers, numberOfUser);
				break;

			case 4:
				cout << " Прощайте! ";
				return;

			default:
				system("cls");
				cout << " Введите коректное число!";
				break;
		}
	}
}

void adminOutput(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {
	system("cls");

	int choice;

	while (true) {
		cout << " 1) работа с таблицей продукции \n 2) работа с таблицей пользователей \n 3) Выйти из системы";

		cin >> choice;
		switch (choice) {
			case 1:
				userOutput(arrayOfProduct, sizeArrayOfData);
				break;
			
			case 2:
				outputWorkdWithUsers(arrayOfUsers, sizeArrayOfUsers);
				break;

			case 3:
				cout << "Прощайте";
				return;

			default:
				cout << "Введите коректное число";
				break;

		}
	}

}

void createNewAccount(Users* arrayOfUsers, int sizeArrayOfUsers) {
	system("cls");
	string password, username;
	arrayOfUsers = resizeUserArray(arrayOfUsers, sizeArrayOfUsers + 1, sizeArrayOfUsers);
	while (true) {
		cout << " Введите логин: "; cin >> username;

		if (!isUsernameCorrect(username, arrayOfUsers, sizeArrayOfUsers - 1)) {
			cout << " этот логин занят, введите новый!!";
		}
	}
	cout << " Введите пароль: "; cin >> password;

	getSalt(arrayOfUsers, password, sizeArrayOfUsers);
	arrayOfUsers[sizeArrayOfUsers].saltedHashPassword = hashing(password);
	arrayOfUsers[sizeArrayOfUsers].role = 0;
	arrayOfUsers[sizeArrayOfUsers].access = 0;

	cout << " Отлично записал, ожидайте одобрение вашего аккаунта";
}

void writeToConsole(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {
	setlocale(LC_ALL, "Russian");
	cout << " 1) Войти \n2) Создать новый аккаунт \n3) Выйти из системы \n";

	string username;
	int choice;
	cout << " Введите ваш выбор: ";
	cin >> choice;
	while(true){
		switch (choice) {
			case 1:
				system("cls");
				username = validation(arrayOfUsers, sizeArrayOfUsers);

				if (isItAdmin(username, arrayOfUsers, sizeArrayOfUsers)) {
					adminOutput(arrayOfProduct, arrayOfUsers, sizeArrayOfData, sizeArrayOfUsers);
				}
				else {
					if (isAccess(username, arrayOfUsers, sizeArrayOfUsers)) {
						userOutput(arrayOfProduct, sizeArrayOfData);
					}
					else {
						cout << " У вас ещё нет доступа";
						break;
					}
				}

			case 2:
				system("cls");
				createNewAccount(arrayOfUsers, sizeArrayOfUsers);
				break;

			case 3:
				system("cls");
				cout << " Прощайте! ";
				return;

			default:
				cout << " Введите коректное число!!";
				break;
		}
	}
}
