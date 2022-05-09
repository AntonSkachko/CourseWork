#include "workingWithUsers.h"

Users* readUserFile(Users*& array, int size) {
	ifstream file;
	file.open("D:\\gitHub\\CourseWork\\CourseWork\\CourseWork\\data\\Users.txt");

	if (!file.is_open()) {
		cout << "We have a problem with users";
	}
	else {
		int numberOfLines = 0;
		while (!file.eof()) {
			if (numberOfLines >= size) {
				array = resizeUserArray(array, size + 1, size);
			}
			file >> array[numberOfLines].nickname;
			file >> array[numberOfLines].saltedHashPassword;
			file >> array[numberOfLines].salt;
			file >> array[numberOfLines].role;
			file >> array[numberOfLines].access;

			numberOfLines++;
		}
		array = resizeUserArray(array, size - 1, size);
		
	}
	file.close();
	return array;
}

void writeInUsersFile(Users* array, int size) {
	ofstream file;
	file.open("D:\\gitHub\\CourseWork\\CourseWork\\CourseWork\\data\\Users.txt", ios::out);
	for (int i = 0; i < size; i++) {
		file << array[i].nickname << " ";
		file << array[i].saltedHashPassword << " ";
		file << array[i].salt << " ";
		file << array[i].role << " ";
		file << array[i].access << endl;
	}
	file.close();
}


Users* resizeUserArray(Users*& array, int newSize, int oldSize) {
	if (oldSize == newSize) {
		return array;
	}

	Users* newArray = new Users[newSize];
	oldSize = newSize < oldSize ? newSize : oldSize;
	for (int i = 0; i < oldSize; i++) {
		newArray[i] = array[i];
	}
	oldSize = newSize;
	delete[] array;
	return newArray;
}

Users* hash(string password, string salt) {
	return NULL;
}

Users* login(Users*& array, int& size) {
	srand(time(NULL));
	array = resizeUserArray(array, size + 1, size);
	
	string login;
	while (true) {
		system("cls");
		cout << "Введите ваш логин: "; cin >> login;
		for (int i = 0; i < size; i++) {
			if (array[i].nickname == login) {
				cout << "Такой человек уже есть введите другое имя";
			}
		}
		array[size].nickname = login;
		break;
	}

	string password;
	cout << "Введите ваш пароль: ";
	cin >> password;

	string salt;
	salt = rand() % 1000;
	array[size].saltedHashPassword = hash(password, salt);
	array[size].salt;

	array[size].role = 0;
	array[size].access = 0;
}

// доделать, но нужно поминть что обычные пользоватили может войти,
// только в том случае если access будет равен 1
// в ином случае должно выводиться "админ не одобрит твоё вход", что-то в этом роде
void authorization(Users* array, int size) {
	string login, password;
	while (true) {
		cout << "Введите ваш логин: "; cin >> login;
		cout << "Введите ваш пароль: "; cin >> password;

		for (int i = 0; i < size; i++) {
			if (array[i].nickname == login) {
				if (array[i].saltedHashPassword != hash(password, array[i].salt)) {
					
				}
			}
		}
	}
}


// admin
void deleteUser(Users*& array, int size, int key) {

	for (int i = key - 1; i < size - 1; i++) {
		array[i] = array[i + 1];
	}
	array = resizeUserArray(array, size - 1, size);
}




