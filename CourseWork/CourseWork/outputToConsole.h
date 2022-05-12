#pragma once

#include "workingWithUsers.h"
#include "workWithData.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

string EnterPassword();
void writeToConsole(ProductInfo* arrayOfData, Users arrayOfUsers, int sizeArrayOfData, int sizeArrayOfUsers);
