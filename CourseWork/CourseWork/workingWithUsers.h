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

// work with array
string getSaltedPassword(string password);

bool isPasswordCorrect(string password, string username, Users* arrayOfUsers, int size);
bool isUsernameCorrect(string username, Users* arrayOfUsers, int size);
bool isItAdmin(string username, Users* arrayOfUsers, int size);
bool isAccess(string username, Users* arrayOfUsers, int size);

long long hash(string password); // make me better
Users* resizeUserArray(Users*& arrayOfUsers, int newSize, int oldSize);

// work with file
void writeInUsersFile(Users* arrayOfUsers, int size);
Users* readUserFile(Users*& arrayOfUsers, int size);

// admin
void deleteUser(Users*& arrayOfUsers, int size, int key);
void approveUser(Users*& arrayOfUsers, int size, string username);

// make in outputToConsole.h
void viewUserArray();

