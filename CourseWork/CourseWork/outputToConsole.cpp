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
	int attempts = 3; // ���������� ������� � ������������
	string username, password;
	while (true) {
		system("cls");

		cout << " ������� �����: "; cin >> username;
		cout << " ������� ������: ";
		password = EnterPassword();

		if (isPasswordCorrect(password, username, arrayOfUsers, sizeArrayOfUsers) &&
			isUsernameCorrect(username, arrayOfUsers, sizeArrayOfUsers)) {
			return username;
		}
		cout << " �������� ������ ��� �����, ���������� �������, � ��� �������� ������� " << attempts;
		--attempts;
		if (attempts == 0) {
			cout << " ��� ����� ��������";
			return;
		}
	}

}

// ����� ������� ��������� ������
void productTableOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(2) << "���� ����� ������ ���������" << setw(2) << "|"
		<< setw(2) << "����� ����" << setw(2) << "|" << setw(2) << "�������� ��������" << setw(2) << "|"
		<< setw(2) << "���������� ���������� ������" << setw(2) << "|" << "��� ������������� �� ���� � ������ ����" << setw(2) << "|\n";
	for (int i = 0; i < sizeArrayOfData; i++) {
		cout << "--------------------------------------------------------------------------------------------";
		cout << "|" << setw(2) << i << setw(2) << "|" << setw(2) << arrayOfProduct[i].dayWhenProductCreate.day << "." <<
			arrayOfProduct[i].dayWhenProductCreate.month << "." << arrayOfProduct[i].dayWhenProductCreate.year << setw(2) << "|"
			<< setw(2) << arrayOfProduct[i].workShopNumber << setw(2) << "|" << setw(2) << arrayOfProduct[i].productName << setw(2) << "|"
			<< setw(2) << arrayOfProduct[i].numberOfProductsProduced << setw(2) << "|" << arrayOfProduct[i].responsiblePerson << setw(2) << "|\n";
	}
	cout << "--------------------------------------------------------------------------------------------";
	
}

// ����� ������� �������������
void userTableOutput(Users* arrayOfUsers, int sizeArrayOfUsers) {
	cout << "|" << setw(2) << "#" << setw(2) << "|" << setw(2) << "��� ������������" << setw(2) << "|"
		<< setw(2) << "������������ ������" << setw(2) << "|"
		<< setw(2) << "����" << setw(2) << "|" << setw(2) << "������" << setw(2) << "|\n";
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
	cout << " �� ������ ������ ����� �����������:\n 1) �� ���� ����� �� ��� ��������� \n"
		<< " ���������� �� ������ ���� \n 3) �� �������� �������� \n 4) �� ���������� ���������� ������"
		<< "\n 5) �� ����� �������������\n";
	int sortingChoice;
	cin >> sortingChoice;
	sorting(arrayOfProduct, sizeArrayOfData, sortingChoice);

	system("cls");
	productTableOutput(arrayOfProduct, sizeArrayOfData);
}

void outputSearch(ProductInfo* arrayOfProduct, int sizeArrayOfProduct) {

}

// ��� ������ �������� � �������� �������������
void userOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData) {
	// sortingChoice � searchingChoice ���������� ��� ������ ������ ���������� � ������ �������������
	
	int choice, searchingChoice, date, element, count, numberOfWorkshop;
	string nameOfProduct, nameOfResponsible;
	ProductInfo* searchingArray;
	Date beginning, end;

	while (true) {
		system("cls");
		cout << "\n 1) ���������� \n 2) ����� \n 3) ����� ���������� ���������� ������� �� ������� ������������ \n 4) �����\n";
		cin >> choice;
		switch (choice) {
			case 1:
				outputSorting(arrayOfProduct, sizeArrayOfData);
				break;

			case 2:
			system("cls");
			productTableOutput(arrayOfProduct, sizeArrayOfData);
			cout << " �� ������ ������ ����� ������:\n 1) �� ��� ����� �� ��� ��������� \n"
				<< " ���������� �� ������ ���� \n 3) �� �������� �������� \n 4) �� ���������� ���������� ������"
				<< "\n 5) �� ����� ������������� \n";
			cin >> searchingChoice;

			system("cls");
			productTableOutput(arrayOfProduct, sizeArrayOfData);

			switch (choice) {

			case 1:
				cout << " ������� ���: ";
				cin >> date;
				searchingArray = searchByDayWhenProductCreate(arrayOfProduct, sizeArrayOfData, date);
				break;

			case 2:
				cout << " ������� ����� ����: ";
				cin >> element;
				searchingArray = searchByWorkShopNumber(arrayOfProduct, sizeArrayOfData, element);
				break;

			case 3:
				cout << " ������� �������� ��������: ";
				cin >> nameOfProduct;
				searchingArray = searchByProductName(arrayOfProduct, sizeArrayOfData, nameOfProduct);
				break;

			case 4:
				cout << " ������� ���������� ���������� ���������: ";
				cin >> count;
				searchingArray = searchByNumberOfProductsProduced(arrayOfProduct, sizeArrayOfData, count);
				break;
			case 5:
				cout << " ������� ������������� � ���� ������� ���������: ";
				cin >> nameOfResponsible;
				searchingArray = searchByResponsiblePerson(arrayOfProduct, sizeArrayOfData, nameOfResponsible);
				break;
			default:
				cout << " ������ ����� ��� �������� �����";

			}
			productTableOutput(searchingArray, 1);

		case 3:
			system("cls");
			cout << " ������� ����� ����: ";
			cin >> numberOfWorkshop;

			cout << " ������� ������ ������� \n ������: \n	����: ";
			cin >> beginning.day;
			cout << "	�����: ";
			cin >> beginning.month;
			cout << "	���:";
			cin >> beginning.year;

			cout << " ������� ������ ������� \n �����: \n	����: ";
			cin >> end.day;
			cout << "	�����: ";
			cin >> end.month;
			cout << "	���:";
			cin >> end.year;
			system("cls");
			productTableOutput(OutputOfNumberOfManufacturedProducts(arrayOfProduct, beginning, end, numberOfWorkshop, sizeArrayOfData), 10);
			break;
		case 4:
			system("cls");
			cout << " ��������! ";
			return;
		default:
			system("cls");
			cout << " ������� ��������� �����!";
		}
	}
}

void adminOutput(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {
	system("cls");

	int choice;

	while (true) {
		cout << " 1) ������ � �������� ��������� \n 2) ������ � �������� ������������� \n 3) �����";

		cin >> choice;
		switch (choice) {
			case 1:
				productTableOutput(arrayOfProduct, sizeArrayOfData)

		}
	}

}

void writeToConsole(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers) {
	setlocale(LC_ALL, "Russian");
	cout << " 1) ����� \n2) ������� ����� ������� \n3) ����� �� ������� \n";

	string username;
	int choice;
	cout << " ������� ��� �����: ";
	cin >> choice;

	switch (choice) {
		case 1: 
			username = validation(arrayOfUsers, sizeArrayOfUsers);
			
			if (isItAdmin(username, arrayOfUsers, sizeArrayOfUsers)) {
				adminOutput(arrayOfProduct, arrayOfUsers, sizeArrayOfData, sizeArrayOfUsers);
			}
			else {
				if (isAccess(username, arrayOfUsers, sizeArrayOfUsers)) {
					userOutput(arrayOfProduct, sizeArrayOfData);
				}
				else {
					cout << " � ��� ��� ��� �������";
					break;
				}
			}

		case 2:



	}

}
