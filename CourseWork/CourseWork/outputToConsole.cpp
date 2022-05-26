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
		cout << " Неверный пароль или логин, повторыите попытку, у вас осталось попыток " << attempts << endl;
		system("pause");
		--attempts;
		if (attempts == 0) {
			cout << " Ваш лимит исчерпан";
			break;
		}
	}

}

// если день или месяц является единичным числом, то к этому числу добавляется 0
string dayWithZero(int date) {
	string resultString = "0";
	if (date < 10) {
		resultString += to_string(date);
		return resultString;
	}
	return to_string(date);
}

// вывод таблицы продуктов склада
void productTableOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(18) << "дата производства" << setw(2) << "|"
		<< setw(11) << "номер цеха" << setw(2) << "|" << setw(18) << "название продукта" << setw(2) << "|"
		<< setw(29) << "количество выпущенных единиц" << setw(2) << "|" << setw(18) << "имя ответсвенного" << setw(3) << "|\n";
	for (int i = 0; i < sizeArrayOfData; i++) {
		cout << "|-----------------------------------------------------------------------------------------------------------|\n";
		cout << "|" << setw(2) << i << setw(2) << "|" << setw(7) << dayWithZero(arrayOfProduct[i].dayWhenProductCreate.day) << "." <<
			dayWithZero(arrayOfProduct[i].dayWhenProductCreate.month) << "." << dayWithZero(arrayOfProduct[i].dayWhenProductCreate.year) << setw(5) << "|"
			<< setw(7) << arrayOfProduct[i].workShopNumber << setw(6) << "|" << setw(11) << arrayOfProduct[i].productName << setw(9) << "|"
			<< setw(15) << arrayOfProduct[i].numberOfProductsProduced << setw(16) << "|" << setw(13) << arrayOfProduct[i].responsiblePerson << setw(8) << "|\n";

	}
	cout << "|-----------------------------------------------------------------------------------------------------------|\n";
	
}

// вывод таблицы пользователей
void userTableOutput(Users* arrayOfUsers, int sizeArrayOfUsers) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(17) << "имя пользователя" << setw(2) << "|"
		<< setw(20) << "хешированный пароль" << setw(2) << "|"
		<< setw(5) << "роль" << setw(2) << "|" << setw(7) << "доступ" << setw(3) << "|\n";
	for (int i = 0; i < sizeArrayOfUsers; i++) {
		cout << "|------------------------------------------------------------|\n";
		cout << "|" << setw(2) << i << setw(2) << "|" << setw(10) << arrayOfUsers[i].nickname << setw(9) << "|"
			<< setw(20) << arrayOfUsers[i].saltedHashPassword << setw(2) << "|"
			<< setw(3) << arrayOfUsers[i].role << setw(4) << "|" << setw(5) << arrayOfUsers[i].access << setw(5) << "|\n";
	}
	cout << "|------------------------------------------------------------|";
}

void outputSorting(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	
	system("cls");
	productTableOutput(arrayOfProduct, sizeArrayOfData);
	cout << " по какому методу будем соритровать:\n 1) по дню когда он был произведён \n"
		<< " 2) сортировка по номеру цеха \n 3) по количеству выпущенных единиц \n 4) выход\n Введите число: ";
	int sortingChoice;
	cin >> sortingChoice;
	if (sortingChoice == 4) {
		return;
	}
	sorting(arrayOfProduct, sizeArrayOfData, sortingChoice);
	system("cls");
	productTableOutput(arrayOfProduct, sizeArrayOfData);
	system("pause");
}

void outputSearch(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	system("cls");
	int searchingChoice, date, element, count, numberOfWorkshop, sizeOfTempArray = 1;
	ProductInfo* searchingArray = new ProductInfo[sizeOfTempArray];
	string nameOfResponsible, nameOfProduct;
	productTableOutput(arrayOfProduct, sizeArrayOfData);
	cout << " по какому методу будем искать:\n 1) по году когда он был произведён \n"
		<< " 2) поиск по номеру цеха \n 3) по названию продукта \n 4) по количеству выпущенных единиц"
		<< "\n 5) по имени ответсвенного \n 6) Выход \n Введите число: ";
	cin >> searchingChoice;

	system("cls");
	productTableOutput(arrayOfProduct, sizeArrayOfData);

	switch (searchingChoice) {

	case 1:
		cout << " Введите год: ";
		cin >> date;
		searchingArray = searchByDayWhenProductCreate(arrayOfProduct, sizeArrayOfData, sizeOfTempArray, date);
		break;

	case 2:
		cout << " Введите номер цеха: ";
		cin >> element;
		searchingArray = searchByWorkShopNumber(arrayOfProduct, sizeArrayOfData, sizeOfTempArray, element);
		break;

	case 3:
		cout << " Введите название продукта: ";
		cin >> nameOfProduct;
		searchingArray = searchByProductName(arrayOfProduct, sizeArrayOfData, sizeOfTempArray, nameOfProduct);
		break;

	case 4:
		cout << " Введите количество выпущенной продукции: ";
		cin >> count;
		searchingArray = searchByNumberOfProductsProduced(arrayOfProduct, sizeArrayOfData, sizeOfTempArray, count);
		break;
	case 5:
		cout << " Введите ответсвенного в день выпуска продукции: ";
		cin >> nameOfResponsible;
		searchingArray = searchByResponsiblePerson(arrayOfProduct, sizeArrayOfData, sizeOfTempArray, nameOfResponsible);
		break;
	case 6:
		return;
	default:
		cout << " такого числа нет попробуй снова";
	}
	
	if (sizeOfTempArray >= 1) {
		productTableOutput(searchingArray, sizeOfTempArray);
		system("pause");
		system("cls");
	}
	else {
		cout << " Введите коректную переменную \n";
		system("pause");
	}

}

void outputIndividualTask(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	system("cls");
	productTableOutput(arrayOfProduct, sizeArrayOfData);
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
	int bufSize;
	auto buf = OutputOfNumberOfManufacturedProducts(arrayOfProduct, beginning, end, numberOfWorkshop, sizeArrayOfData, bufSize);
	if (bufSize == 0) {
		cout << " Вы ввели неправильную информацию \n ";
		system("pause");
		return;
	}
	productTableOutput(buf, bufSize);
	system("pause");
	system("cls");
}

// что должно выводить у обычного пошльзователя
void userOutput(ProductInfo*& arrayOfProduct, int sizeArrayOfData, int choice) {
	// sortingChoice и searchingChoice переменные для выбора метода сортировки и поиска соответсвенно
	
	int sizeArrayOfProduct;
	string nameOfProduct, nameOfResponsible;
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

		default:
			system("cls");
			cout << " Введите коректное число!";
	}
}

void outputWorkdWithUsers(Users*& arrayOfUsers, int& sizeArrayOfUsers) {
	int choiceOfUserTable, numberOfUser;
	string newName;
	while (true) {
		system("cls");
		userTableOutput(arrayOfUsers, sizeArrayOfUsers);
		cout << "\n 1) удаление пользователя\n 2) одобрить регестрацию \n 3) сделать человека админом \n 4) изменить имя пользователя \n 5) выход \n Введите номер: ";
		cin >> choiceOfUserTable;
		switch (choiceOfUserTable) {
			case 1:
				cout << "\n Введите номер удаляемого пользователя: ";
				cin >> numberOfUser;

				deleteUser(arrayOfUsers, sizeArrayOfUsers, numberOfUser);
				break;

			case 2:
				cout << " Введите номер одобряемого пользователя: ";
				cin >> numberOfUser;

				approveUser(arrayOfUsers, sizeArrayOfUsers, numberOfUser);
				break;

			case 3:
				cout << " Введите номер человека, который станет тоже админом: ";
				cin >> numberOfUser;

				makeUserAdmin(arrayOfUsers, sizeArrayOfUsers, numberOfUser);
				break;
			
			case 4:
				cout << " Введите номер человека, у коготого изменим имя: ";
				cin >> numberOfUser;
				cout << " Введите новоё имя: ";
				cin >> newName;
				changeUsername(arrayOfUsers, sizeArrayOfUsers, numberOfUser, newName);
				break;
			case 5:
				cout << " Прощайте! ";
				system("cls");
				return;

			default:
				system("cls");
				cout << " Введите коректное число!";
				break;
		}
	}
}
void displayAdditionalFeatures(ProductInfo*& arrayOfProduct, int& sizeArrayOfData, int choiceOfProduct) {
	int deletingElement;
	switch (choiceOfProduct) {
		case 5:
			system("cls");
			productTableOutput(arrayOfProduct, sizeArrayOfData);
			addInArray(arrayOfProduct, sizeArrayOfData);
			cout << " Элемент успешно добавлен\n";
			system("pause");
			break;
		
		case 6:
			system("cls");
			productTableOutput(arrayOfProduct, sizeArrayOfData);
			cout << " Введите номер удаляемого элемента: ";
			cin >> deletingElement;
			deleteElement(arrayOfProduct, sizeArrayOfData, deletingElement);
			cout << " Элемент успешно удалён\n";
			system("pause");
			break;
	}
}

void adminOutput(ProductInfo*& arrayOfProduct, Users*& arrayOfUsers, int& sizeArrayOfData, int& sizeArrayOfUsers) {

	int choice, choiceOfProduct;

	while (true) {
		system("cls");
		cout << " 1) работа с таблицей продукции \n 2) работа с таблицей пользователей \n 3) Выйти из системы \n Введите номер: ";

		cin >> choice;
		switch (choice) {
			case 1:
				while (true) {
					system("cls");
					productTableOutput(arrayOfProduct, sizeArrayOfData);
					cout << "\n 1) сортировка \n 2) поиск \n 3) вывод количество выпущенных изделий по каждому наименованию \n 4) выход";
					cout << "\n 5) добовление продукта\n 6) удаление продукта \n ";
					cout << " Введите номер: ";
					cin >> choiceOfProduct;
					if (choiceOfProduct < 4) {
						userOutput(arrayOfProduct, sizeArrayOfData, choiceOfProduct);
					}
					else if(choiceOfProduct == 4) {
						cout << " Прощайте\n";
						break;
					}
					else {
						displayAdditionalFeatures(arrayOfProduct, sizeArrayOfData, choiceOfProduct);
					}
					
				}
				break;
			
			case 2:
				system("cls");
				outputWorkdWithUsers(arrayOfUsers, sizeArrayOfUsers);
				break;

			case 3:
				system("cls");
				cout << "Прощайте\n";
				return;

			default:
				cout << "Введите коректное число";
				break;

		}
	}

}

void createNewAccount(Users*& arrayOfUsers, int &sizeArrayOfUsers) {
	system("cls");
	string password, username;
	int countOfMistake = 3;
	arrayOfUsers = resizeUserArray(arrayOfUsers, sizeArrayOfUsers + 1, sizeArrayOfUsers);
	while (countOfMistake != 0) {
		cout << " Введите логин: "; cin >> username;

		if (isUsernameCorrect(username, arrayOfUsers, sizeArrayOfUsers - 1)) {
			cout << " этот логин занят, введите новый!!\n";
			cout << " У вас осталось ввести " << countOfMistake << " раза\n";
			countOfMistake--;
			if (countOfMistake == 0) {
				cout << " У вас не осталось попыток";
				return;
			}
		}
		else {
			break;
		}
	}
	cout << " Введите пароль: "; cin >> password;

	getSalt(arrayOfUsers, password, sizeArrayOfUsers - 1);
	password += arrayOfUsers[sizeArrayOfUsers - 1].salt;
	arrayOfUsers[sizeArrayOfUsers - 1].saltedHashPassword = hashing(password);
	arrayOfUsers[sizeArrayOfUsers - 1].role = 0;
	arrayOfUsers[sizeArrayOfUsers - 1].access = 0;
	arrayOfUsers[sizeArrayOfUsers - 1].nickname = username;

	cout << " Отлично записал, ожидайте одобрение вашего аккаунта \n";
}

void writeToConsole(ProductInfo* arrayOfProduct, Users*& arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {
	setlocale(LC_ALL, "Russian");
	
	string username;
	int choice, choiceOfUsers;
	while(true){
		system("cls");
		cout << " 1) Войти \n 2) Создать новый аккаунт \n 3) Выйти из системы \n";
		cout << " Введите ваш выбор: ";
		cin >> choice;

		switch (choice) {
			case 1:
				system("cls");
				username = validation(arrayOfUsers, sizeArrayOfUsers);

				if (isItAdmin(username, arrayOfUsers, sizeArrayOfUsers)) {
					adminOutput(arrayOfProduct, arrayOfUsers, sizeArrayOfData, sizeArrayOfUsers);
				}
				else {
					if (isAccess(username, arrayOfUsers, sizeArrayOfUsers)) {
						cout << "\n 1) сортировка \n 2) поиск \n 3) вывод количество выпущенных изделий по каждому наименованию \n 4) выход\n";
						cin >> choiceOfUsers;
						if (choiceOfUsers == 4) {
							cout << " Прощайте!\n ";
							break;
						}
						system("cls");
						productTableOutput(arrayOfProduct, sizeArrayOfData);
						userOutput(arrayOfProduct, sizeArrayOfData, choiceOfUsers);
					}
					else {
						system("cls");
						cout << " У вас ещё нет доступа\n";
						system("pause");
						break;
					}
				}
				break;
			case 2:
				system("cls");
				createNewAccount(arrayOfUsers, sizeArrayOfUsers);
				system("pause");
				break;

			case 3:
				system("cls");
				cout << " Прощайте! \n";
				writeInUsersFile(arrayOfUsers, sizeArrayOfUsers);
				writeInFile(arrayOfProduct, sizeArrayOfData);
				system("pause");
				return;

			default:
				cout << " Введите коректное число!!";
				break;
		}
	}
}
