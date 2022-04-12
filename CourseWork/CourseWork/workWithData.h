#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <algorithm>
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
void addInArray(ProductInfo*& array, int& size);
void deleteElement(ProductInfo*& array, int& size, int deletingElement);
void writeInFile(ProductInfo* array, int size);

// work with array
bool compByDayWhenProductCreate(ProductInfo& begin, ProductInfo& end);
bool compByWorkShopNumber(ProductInfo& begin, ProductInfo& end);
bool compByProductName(ProductInfo& begin, ProductInfo& end);
bool compByNumberOfProductsProduced(ProductInfo& begin, ProductInfo& end);
bool compByResponsiblePerson(ProductInfo& begin, ProductInfo& end);

void sorting(ProductInfo*& array, int size, int choice);
void search(ProductInfo* array, int size);

// make bettter name!!
ProductInfo* IndividualTask(ProductInfo* array, Date beginning, Date end, int size);

// other func
Date getCurrentDate();
int day(ProductInfo* array);