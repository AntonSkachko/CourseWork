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
ProductInfo* readFile(ProductInfo*& arrayOfData, int size);
ProductInfo* resizeArray(int& oldSize, int newSize, ProductInfo* arrayOfData);
void addInArray(ProductInfo*& arrayOfData, int& size);
void deleteElement(ProductInfo*& arrayOfData, int& size, int deletingElement);
void writeInFile(ProductInfo* arrayOfData, int size);

// work with array
bool compByDayWhenProductCreate(ProductInfo& begin, ProductInfo& end);
bool compByWorkShopNumber(ProductInfo& begin, ProductInfo& end);
bool compByProductName(ProductInfo& begin, ProductInfo& end);
bool compByNumberOfProductsProduced(ProductInfo& begin, ProductInfo& end);
bool compByResponsiblePerson(ProductInfo& begin, ProductInfo& end);

void sorting(ProductInfo*& arrayOfData, int size, int choice);
void search(ProductInfo* arrayOfData, int size);

// make bettter name!!
ProductInfo* IndividualTask(ProductInfo* arrayOfData, Date beginning, Date end, int size);
Date getCurrentDate();
int day(ProductInfo* arrayOfData);

// other func