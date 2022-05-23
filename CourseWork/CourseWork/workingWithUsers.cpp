#include "workingWithUsers.h"

void readUserFile(Users*& arrayOfUsers, int& size) {
	ifstream file("account.txt");
	if (!file.is_open()) {
		cout << "у нас проблемы с чтени€ файла с пользовател€ми\n";
	}
	else {
		int numberOfLines = 0;
		while (!file.eof()) {
			if (numberOfLines >= size) {
				arrayOfUsers = resizeUserArray(arrayOfUsers, size + 1, size);
			}
			file >> arrayOfUsers[numberOfLines].nickname;
			file >> arrayOfUsers[numberOfLines].saltedHashPassword;
			file >> arrayOfUsers[numberOfLines].salt;
			file >> arrayOfUsers[numberOfLines].role;
			file >> arrayOfUsers[numberOfLines].access;

			numberOfLines++;
		}
		--size;
		
	}
	file.close();
}

void writeInUsersFile(Users* arrayOfUsers, int size) {
	ofstream file("account.txt");
	for (int i = 0; i < size; i++) {
		file << arrayOfUsers[i].nickname << " ";
		file << arrayOfUsers[i].saltedHashPassword << " ";
		file << arrayOfUsers[i].salt << " ";
		file << arrayOfUsers[i].role << " ";
		file << arrayOfUsers[i].access << endl;
	}
	file.close();
}


Users* resizeUserArray(Users*& arrayOfUsers, int newSize, int& oldSize) {
	if (oldSize == newSize) {
		return arrayOfUsers;
	}
	Users* newArray = new Users[newSize];
	oldSize = newSize < oldSize ? newSize : oldSize;
	for (int i = 0; i < oldSize; i++) {
		newArray[i] = arrayOfUsers[i];
	}
	oldSize = newSize;
	delete[] arrayOfUsers;
	return newArray;
}


void deleteUser(Users*& arrayOfUsers, int& size, int key) {

	for (int i = key; i < size - 1; i++) {
		arrayOfUsers[i] = arrayOfUsers[i + 1];
	}
	--size;
}


long long hashing(string& password) {
	long long cons = 987432869, sum = 1;
	for (int i = 0; i < password.size(); i++) {
		sum = sum * cons + password[i];
	}
	return sum;
}

void getSalt(Users*& arrayOfUsers, string password, int key) {
	srand(hashing(password));
	string salt = "";

	const int NEW_SYMBOL_COUNT = 10;
	const int SYMBOL_COUNT = 90;
	const int MIN_SYMBOL = 32;

	for (int ind = 0; ind < NEW_SYMBOL_COUNT; ind++) {
		salt += rand() % SYMBOL_COUNT + MIN_SYMBOL;
	}
	arrayOfUsers[key].salt = salt;
}

long long getSaltedPassword(string& password, Users* arrayOfUsers, int key) {
	srand(hashing(password));
	string newPassword = password;
	newPassword += arrayOfUsers[key].salt;
	return hashing(newPassword);
}

bool isUsernameCorrect(string username, Users* arrayOfUsers, int size) {
	for (int i = 0; i < size; i++) {
		if (arrayOfUsers[i].nickname == username) {
			return true;
		}
	}
	return false;
}

bool isPasswordCorrect(string password, string username, Users* arrayOfUsers, int size) {
	for (int userIndex = 0; userIndex < size; userIndex++) {
		if (arrayOfUsers[userIndex].nickname == username) {
	
			if (getSaltedPassword(password, arrayOfUsers, userIndex) == arrayOfUsers[userIndex].saltedHashPassword) {
				return true;
			}
		}
	}
	return false;
}

bool isItAdmin(string username, Users* arrayOfUsers, int size) {
	// если человек под именем username €вл€етс€ админом, то arrayOfUsers.role будет true

	for (int i = 0; i < size; i++) {
		if (arrayOfUsers[i].nickname == username) {
			return arrayOfUsers[i].role;
		}
	}
}

bool isAccess(string username, Users* arrayOfUsers, int size) {

	for (int i = 0; i < size; i++) {
		if (arrayOfUsers[i].nickname == username) {
			return arrayOfUsers[i].access;
		}
	}
}

void approveUser(Users*& arrayOfUsers, int size, int key) {
	arrayOfUsers[key].access = 1;
}

void makeUserAdmin(Users*& arrayOfUsers, int size, int key) {
	arrayOfUsers[key].role = 1;
}
