#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Users {
	string nickname;
	long long saltedHashPassword;
	string salt;
	bool role;
	bool access;
};

// work with array

bool isPasswordCorrect(string password, string username, Users* arrayOfUsers, int size);
bool isUsernameCorrect(string username, Users* arrayOfUsers, int size);
bool isItAdmin(string username, Users* arrayOfUsers, int size);
bool isAccess(string username, Users* arrayOfUsers, int size);

long long hashing(string& password);
void getSalt(Users*& arrayOfUsers, string password, int key);
long long getSaltedPassword(string& password, Users* arrayOfUsers, int key);
Users* resizeUserArray(Users*& arrayOfUsers, int newSize, int& oldSize);

// work with file
void writeInUsersFile(Users* arrayOfUsers, int size);
void readUserFile(Users*& arrayOfUsers, int& size);

// admin
void deleteUser(Users*& arrayOfUsers, int& size, int key);
void approveUser(Users*& arrayOfUsers, int size, int key);
void makeUserAdmin(Users*& arrayOfUsers, int size, int key);

