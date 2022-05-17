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
void writeToConsole(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers);

void outputSorting(ProductInfo* arrayOfProduct, int sizeArrayOfData);
void outputSearch(ProductInfo* arrayOfProduct, int sizeArrayOfData);


void adminOutput(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers);
void userOutput(ProductInfo* arrayOfProduct, int sizeArrayOfData);