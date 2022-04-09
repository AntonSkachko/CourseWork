#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

struct ProductInfo {
	Date dayWhenProductCreate;
	int workShopNumber;
	string productName;
	int numberOfProductsProduced;
	string responsiblePerson;
};

// work with file
ProductInfo* readFile(ProductInfo* array, int size);
ProductInfo* resizeArray(int& oldSize, int newSize, ProductInfo* array);
void addInFile(ProductInfo temp, int size);
void deleteElement(ProductInfo*& array, int& size, int deletingElement);

// work with array
void sorting(ProductInfo*& array, int size, int choice);
void search(ProductInfo* array, int size);

// make bettter name!!
ProductInfo* IndividualTask(ProductInfo* array, Date beginning, Date end, int size);

// other func
Date getCurrentDate();
int day(ProductInfo* array);