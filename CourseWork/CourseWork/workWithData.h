#pragma once

#include <fstream>
#include <string>
using namespace std;

struct ProductInformation {
	int date;
	int workshopNumber;
	string productName;
	int numberOfProductsProduced;
	string responsiblePerson;
};
void readFile();
void resizeArray();
void addInFile();


