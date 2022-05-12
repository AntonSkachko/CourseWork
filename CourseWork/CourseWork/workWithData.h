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
ProductInfo* readFile(ProductInfo*& arrayOfProduct, int size);
ProductInfo* resizeArray(int& oldSize, int newSize, ProductInfo* arrayOfProduct);
void addInArray(ProductInfo*& arrayOfProduct, int& size);
void deleteElement(ProductInfo*& arrayOfProduct, int& size, int deletingElement);
void writeInFile(ProductInfo* arrayOfProduct, int size);

// work with array
bool compByDayWhenProductCreate(ProductInfo& begin, ProductInfo& end);
bool compByWorkShopNumber(ProductInfo& begin, ProductInfo& end);
bool compByProductName(ProductInfo& begin, ProductInfo& end);
bool compByNumberOfProductsProduced(ProductInfo& begin, ProductInfo& end);
bool compByResponsiblePerson(ProductInfo& begin, ProductInfo& end);

void sorting(ProductInfo*& arrayOfProduct, int size, int choice);
void searchByDayWhenProductCreate(ProductInfo*& arrayOfProduct, int size, int start, int finish);

// make bettter name!!
ProductInfo* IndividualTask(ProductInfo* arrayOfProduct, Date beginning, Date end, int size);
Date getCurrentDate();
int day(ProductInfo* arrayOfProduct);

// other func