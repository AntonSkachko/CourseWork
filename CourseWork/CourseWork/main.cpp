/**
	  ---------------------------------------------------
	  |        Made by Skachko Anton (@jAnt0n228)       |
	  |             2021 - BSUIR - FCP - PMS            |
	  |          *** All rights reserved ***			|
	  |													|
	  |	        	\_____________________/				|
	  |	        	 ___/__|_______|__\___				|
	  |	        	 /+++  _________  +++\				|
	  |	        	 \___ /_GTR R34_\ ___/				|
	  |	        	 \_|_|_|       |_|_|_/				|
	  ---------------------------------------------------
														   **/

#include "outputToConsole.h"
#include "workingWithUsers.h"
#include "workWithData.h"
#include <iostream>
using namespace std; 


int main() {
	setlocale(LC_ALL, "Russian");
	int sizeArrayOfData = 1, sizeArrayOfUsers = 1;
	ProductInfo* arrayOfData = new ProductInfo[sizeArrayOfData];
	readProductFile(arrayOfData, sizeArrayOfData);
	
	Users* arrayOfUsers = new Users[sizeArrayOfUsers];
	readUserFile(arrayOfUsers, sizeArrayOfUsers);
	
	writeToConsole(arrayOfData, arrayOfUsers, sizeArrayOfData, sizeArrayOfUsers);


	return 0;
}
