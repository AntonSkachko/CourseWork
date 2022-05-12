#include "workingWithUsers.h"

Users* readUserFile(Users*& arrayOfUsers, int size) {
	ifstream file;
	file.open("D:\\gitHub\\CourseWork\\CourseWork\\CourseWork\\data\\Users.txt");

	if (!file.is_open()) {
		cout << "We have a problem with users";
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
		arrayOfUsers = resizeUserArray(arrayOfUsers, size - 1, size);
		
	}
	file.close();
	return arrayOfUsers;
}

void writeInUsersFile(Users* arrayOfUsers, int size) {
	ofstream file;
	file.open("D:\\gitHub\\CourseWork\\CourseWork\\CourseWork\\data\\Users.txt", ios::out);
	for (int i = 0; i < size; i++) {
		file << arrayOfUsers[i].nickname << " ";
		file << arrayOfUsers[i].saltedHashPassword << " ";
		file << arrayOfUsers[i].salt << " ";
		file << arrayOfUsers[i].role << " ";
		file << arrayOfUsers[i].access << endl;
	}
	file.close();
}


Users* resizeUserArray(Users*& arrayOfUsers, int newSize, int oldSize) {
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


// admin
void deleteUser(Users*& arrayOfUsers, int size, int key) {

	for (int i = key - 1; i < size - 1; i++) {
		arrayOfUsers[i] = arrayOfUsers[i + 1];
	}
	arrayOfUsers = resizeUserArray(arrayOfUsers, size - 1, size);
}


// ? откуда числа 15 106 и 21
string getSaltedPassword(string password) {
	srand(time(NULL));
	const int SALT_SIZE = 15;
	for (int elSalt = 0; elSalt < SALT_SIZE; ++elSalt) {
		password += char(rand() % 106 + 21);
	}
	return password;
}


// это вообще что, нужно разобрать
long long hash(const string password) {
	
	const long long hash_const_first = 958038479;
	const long long hash_const_second = 1013572099;
	long long hash_cur_val = hash_const_first;
	long long hash_first = 0;
	long long hash_second = 0;
	
	for (auto symbol : password) {
		hash_first += hash_cur_val * symbol;
		hash_cur_val *= hash_const_first;
	}
	for (auto symbol : password) {
		hash_second += hash_cur_val * symbol;
		hash_cur_val *= hash_const_second;
	}
	return hash_first * (11 * hash_const_second - 7 * hash_const_first)
		+ hash_second * (13 * hash_const_first + 5 * hash_const_second);
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
	int userIndex = 0;
	for (; userIndex < size; userIndex++) {
		if (arrayOfUsers[userIndex].nickname == username) {
	
		//if (hash(getSaltedPassword(password) == arrayOfUsers[userIndex].saltedHashPassword) {
		//	return true;
		//}
		break;
		}
	}
	return false;
}

bool isItAdmin(string username, Users* arrayOfUsers, int size) {
	// если человек под именем username является админом, то arrayOfUsers.role будет true

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

void approveUser(Users*& arrayOfUsers, int size, string username) {
	if (isUsernameCorrect(username, arrayOfUsers, size)) {
		return;
	}
	for (int i = 0; i < size; i++) {
		if (arrayOfUsers[i].nickname == username) {
			arrayOfUsers[i].access == 1;
		}
	}
}
