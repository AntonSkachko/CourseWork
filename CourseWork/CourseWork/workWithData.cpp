#include "workWithData.h"

ProductInfo* resizeArray(int& oldSize, int newSize, ProductInfo* arrayOfProduct
) {
	if (oldSize == newSize) {
		return arrayOfProduct;
	}
	
	ProductInfo* newArray = new ProductInfo[newSize];
	oldSize = newSize < oldSize ? newSize : oldSize;
	for (int i = 0; i < oldSize; i++) {
		newArray[i] = arrayOfProduct[i];
	}
	oldSize = newSize;
	delete[] arrayOfProduct;
	return newArray;
}

void readProductFile(ProductInfo*& arrayOfProduct, int size) {
	ifstream file;
	file.open("D:\\gitHub\\CourseWork\\CourseWork\\CourseWork\\data\\productFile.txt");

	if (!file.is_open()) {
		cout << "We have a problem with Data" << endl;
	}
	else {
		int numberOfLines = 0;
		while (!file.eof()) {
			if (numberOfLines >= size) {
				arrayOfProduct = resizeArray(size, size + 1, arrayOfProduct);
			}
			file >> arrayOfProduct[numberOfLines].dayWhenProductCreate.day;
			file >> arrayOfProduct[numberOfLines].dayWhenProductCreate.month;
			file >> arrayOfProduct[numberOfLines].dayWhenProductCreate.year;
			file >> arrayOfProduct[numberOfLines].workShopNumber;
			file >> arrayOfProduct[numberOfLines].productName;
			file >> arrayOfProduct[numberOfLines].numberOfProductsProduced;
			file >> arrayOfProduct[numberOfLines].responsiblePerson;

			numberOfLines++;
		}
		arrayOfProduct = resizeArray(size, size - 1, arrayOfProduct);
	}
	file.close();
}


void addInArray(ProductInfo*& arrayOfProduct, int& size) {
	arrayOfProduct = resizeArray(size, size + 1, arrayOfProduct);
	cout << "Enter day when this product create: \n";
	cout << "Day: "; cin >> arrayOfProduct[size].dayWhenProductCreate.day;
	cout << "Month: "; cin >> arrayOfProduct[size].dayWhenProductCreate.month;
	cout << "Year: "; cin >> arrayOfProduct[size].dayWhenProductCreate.year;

	cout << "Enter work Shop number: "; cin >> arrayOfProduct[size].workShopNumber;
	
	cout << "Enter product Name: "; cin >> arrayOfProduct[size].productName;
	
	cout << "Enter number of product produced: "; cin >> arrayOfProduct[size].numberOfProductsProduced;

	cout << "Enter resposible person: "; cin >> arrayOfProduct[size].responsiblePerson;
}

bool compByDayWhenProductCreate(ProductInfo& begin, ProductInfo& end) {
	return begin.dayWhenProductCreate.year < begin.dayWhenProductCreate.year;
}

bool compByWorkShopNumber(ProductInfo& begin, ProductInfo& end) {
	return begin.workShopNumber < end.workShopNumber;
}

bool compByProductName(ProductInfo& begin, ProductInfo& end) {
	return begin.productName < end.productName;
}

bool compByNumberOfProductsProduced(ProductInfo& begin, ProductInfo& end) {
	return begin.numberOfProductsProduced < end.numberOfProductsProduced;
}

bool compByResponsiblePerson(ProductInfo& begin, ProductInfo& end) {
	return begin.responsiblePerson < end.responsiblePerson;
	
}

void sorting(ProductInfo*& arrayOfProduct, int size, int choice) {
	
	/* 1 - sorting by date (int)
	   2 - sorting by workShopNumber (int)
	   3 - sorting by productName (string)
	   4 - sorting by numberOfProductsProduced (int)
	   5 - sorting by responsiblePerson (string)
	
	*/
	
	switch (choice) {
		// TO DO сделать более нормальную сортировку с учётом месяца и дня
		case 1:
			sort(arrayOfProduct, arrayOfProduct + size, compByDayWhenProductCreate);
			break;
		
		case 2:
			sort(arrayOfProduct, arrayOfProduct + size, compByWorkShopNumber);
			break;
		
		case 3:
			sort(arrayOfProduct, arrayOfProduct + size, compByProductName);
			break;

		case 4: 
			sort(arrayOfProduct, arrayOfProduct + size, compByNumberOfProductsProduced);
			break;

		case 5: 
			sort(arrayOfProduct, arrayOfProduct + size, compByResponsiblePerson);
			break;

	}
}


// поиск по году когда он произведён
ProductInfo* searchByDayWhenProductCreate(ProductInfo* arrayOfProduct, int size, int date) {
	int sizeOfTempArray = 1;
	ProductInfo* tempArray = new ProductInfo[sizeOfTempArray];

	for (int numberOfProduct = 0; numberOfProduct < size; numberOfProduct++) {
		if (arrayOfProduct[numberOfProduct].dayWhenProductCreate.year == date) {
			tempArray[sizeOfTempArray - 1] = arrayOfProduct[numberOfProduct];
			tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray + 1, tempArray);
		}
	}
	tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray - 1, tempArray);
	return tempArray;
}

// поиск по номеру цеха
ProductInfo* searchByWorkShopNumber(ProductInfo* arrayOfProduct, int size, int element) {
	int sizeOfTempArray = 1;
	ProductInfo* tempArray = new ProductInfo[sizeOfTempArray];

	for (int numberOfProduct = 0; numberOfProduct < size; numberOfProduct++) {
		if (arrayOfProduct[numberOfProduct].workShopNumber == element) {
			tempArray[sizeOfTempArray - 1] = arrayOfProduct[numberOfProduct];
			tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray + 1, tempArray);
		}
	}
	tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray - 1, tempArray);
	return tempArray;
}

// поиск по имени продукта
ProductInfo* searchByProductName(ProductInfo* arrayOfProduct, int size, string nameOfProduct) {
	int sizeOfTempArray = 1;
	ProductInfo* tempArray = new ProductInfo[sizeOfTempArray];

	for (int numberOfProduct = 0; numberOfProduct < size; numberOfProduct++) {
		if (arrayOfProduct[numberOfProduct].productName == nameOfProduct) {
			tempArray[sizeOfTempArray - 1] = arrayOfProduct[numberOfProduct];
			tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray + 1, tempArray);
		}
	}
	tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray - 1, tempArray);
	return tempArray;
}

// поиск по количеству выпущенных единиц
ProductInfo* searchByNumberOfProductsProduced(ProductInfo* arrayOfProduct, int size, int count) {
	int sizeOfTempArray = 1;
	ProductInfo* tempArray = new ProductInfo[sizeOfTempArray];

	for (int numberOfProduct = 0; numberOfProduct < size; numberOfProduct++) {
		if (arrayOfProduct[numberOfProduct].numberOfProductsProduced == count) {
			tempArray[sizeOfTempArray - 1] = arrayOfProduct[numberOfProduct];
			tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray + 1, tempArray);
		}
	}
	tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray - 1, tempArray);
	return tempArray;
}

// поиск по ответсвенному в это дату выпуска продукции
ProductInfo* searchByResponsiblePerson(ProductInfo* arrayOfProduct, int size, string person) {
	int sizeOfTempArray = 1;
	ProductInfo* tempArray = new ProductInfo[sizeOfTempArray];

	for (int numberOfProduct = 0; numberOfProduct < size; numberOfProduct++) {
		if (arrayOfProduct[numberOfProduct].responsiblePerson == person) {
			tempArray[sizeOfTempArray - 1] = arrayOfProduct[numberOfProduct];
			tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray + 1, tempArray);
		}
	}
	tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray - 1, tempArray);
	return tempArray;
}


// будет выводиться таблица элементов с нумерацией и пользователь выбирает
// deletingElement который будет удалять
void deleteElement(ProductInfo*& arrayOfProduct, int& size, int deletingElement) {
	//нужно придумать как удалять элемент с файла
	
	for (int i = deletingElement - 1; i < size - 1; i++) {
		arrayOfProduct[i] = arrayOfProduct[i + 1];
	}
	arrayOfProduct = resizeArray(size, size - 1, arrayOfProduct);
}

// TO DO better !!!!!!!
Date getCurrentDate() {
	tm localTime;
	time_t now = time(NULL);
	localtime_s(&localTime, &now);
	Date currentDate;
	currentDate.day = localTime.tm_mday;
	currentDate.month = 1 + localTime.tm_mon;
	currentDate.year = 1900 + localTime.tm_year;
	return currentDate;
}

int convertToDay(Date day) {
	int numberOfDays;
	numberOfDays = day.day + day.month * 30 + day.year * 365;
	return numberOfDays;
}

ProductInfo* OutputOfNumberOfManufacturedProducts(ProductInfo* arrayOfProduct, Date beginning, Date end, int numberOfWorkshop, int size) {
	int sizeOfManufacturedProduct = 1;
	ProductInfo* manufacturedProducts = new ProductInfo[sizeOfManufacturedProduct];

	for (int i = 0; i < size; i++) {
		if (arrayOfProduct[i].workShopNumber == numberOfWorkshop) {
			if (convertToDay(arrayOfProduct[i].dayWhenProductCreate) >= convertToDay(beginning) ||
				convertToDay(arrayOfProduct[i].dayWhenProductCreate) <= convertToDay(end)) {
				manufacturedProducts[sizeOfManufacturedProduct - 1] = arrayOfProduct[i];
				
				manufacturedProducts = resizeArray(sizeOfManufacturedProduct, sizeOfManufacturedProduct + 1, manufacturedProducts);
			}
		}
	}
	manufacturedProducts = resizeArray(sizeOfManufacturedProduct, sizeOfManufacturedProduct - 1, manufacturedProducts);
	return manufacturedProducts;
}
// you need to complete individual Task

void writeInFile(ProductInfo* arrayOfProduct, int size) {
	ofstream file;
	file.open("D:\gitHub\CourseWork\CourseWork\CourseWork\data\\productFile.txt", ios::out);
	for (int i = 0; i < size; i++) {
		file << arrayOfProduct[i].dayWhenProductCreate.day << " ";
		file << arrayOfProduct[i].dayWhenProductCreate.month << " ";
		file << arrayOfProduct[i].dayWhenProductCreate.year << " ";
		file << arrayOfProduct[i].numberOfProductsProduced << " ";
		file << arrayOfProduct[i].productName << " ";
		file << arrayOfProduct[i].responsiblePerson << " ";
		file << arrayOfProduct[i].workShopNumber << endl;
	}
	file.close();
	delete[] arrayOfProduct;
}