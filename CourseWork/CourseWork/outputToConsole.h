#pragma once

#include "workingWithUsers.h"
#include "workWithData.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void productTableOutPut(ProductInfo* arrayOfProduct, int sizeArrayOfData);
string EnterPassword();
void writeToConsole(ProductInfo* arrayOfProduct, Users* arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers);
