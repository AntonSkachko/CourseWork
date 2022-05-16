#include "outputToConsole.h"
#include "workingWithUsers.h"
#include "workWithData.h"
#include <iostream>
using namespace std; 


int main() {
	cout << day(nullptr) << '\n';
	setlocale(LC_ALL, "Russian");
	
	int sizeArrayOfData = 1, sizeArrayOfUsers = 1;
	ProductInfo* arrayOfData = new ProductInfo[sizeArrayOfData];
	Users* arrayOfUsers = new Users[sizeArrayOfUsers];
	
	readProductFile(arrayOfData, sizeArrayOfData);
	readUserFile(arrayOfUsers, sizeArrayOfUsers);

	writeToConsole(arrayOfData, arrayOfUsers, sizeArrayOfData, sizeArrayOfUsers);

	return 0;
}
