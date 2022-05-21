#pragma once

#include "workingWithUsers.h"
#include "workWithData.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

void productTableOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData);
void userTableOutput(Users* arrayOfUsers, int sizeArrayOfUsers);

string validation(Users* arrayOfUsers, int sizeArrayOfUsers);
string EnterPassword();

// the main function
void writeToConsole(ProductInfo* arrayOfProduct, Users*& arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers);
// the main funciton 


void outputSorting(ProductInfo* arrayOfProduct, int sizeArrayOfData);
void outputSearch(ProductInfo* arrayOfProduct, int sizeArrayOfData);
void outputIndividualTask(ProductInfo* arrayOfProduct, int sizeArrayOfData);
void outputWorkWithUsers(Users*& arrayOfUsers, int sizeArrayOfUsers);


void adminOutput(ProductInfo*& arrayOfProduct, Users*& arrayOfUsers, int& sizeArrayOfData, int& sizeArrayOfUsers);
void userOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData);

void createNewAccount(Users*& arrayOfUsers, int& sizeArrayOfUsers);

