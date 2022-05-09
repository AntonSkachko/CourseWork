#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Users {
	string nickname;
	int saltedHashPassword;
	string salt;
	bool role;
	bool access;
};

Users* hash(string password, string salt);
Users* resizeUserArray(Users*& array, int newSize, int oldSize);
Users* login(Users*& array, int& size);
void writeInUsersFile(Users* array, int size);
void authorization(Users* array, int size);
void deleteUser(Users*& array, int size, int key);

