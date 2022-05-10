#include "workWithData.h"

ProductInfo* resizeArray(int& oldSize, int newSize, ProductInfo* arrayOfData) {
	if (oldSize == newSize) {
		return arrayOfData;
	}
	
	ProductInfo* newArray = new ProductInfo[newSize];
	oldSize = newSize < oldSize ? newSize : oldSize;
	for (int i = 0; i < oldSize; i++) {
		newArray[i] = arrayOfData[i];
	}
	oldSize = newSize;
	delete[] arrayOfData;
	return newArray;
}

ProductInfo* readFile(ProductInfo*& arrayOfData, int size) {
	ifstream file;
	file.open("D:\\gitHub\\CourseWork\\CourseWork\\CourseWork\\data\\productFile.txt");

	if (!file.is_open()) {
		cout << "We have a problem with Data" << endl;
	}
	else {
		int numberOfLines = 0;
		while (!file.eof()) {
			if (numberOfLines >= size) {
				arrayOfData = resizeArray(size, size + 1, arrayOfData);
			}
			file >> arrayOfData[numberOfLines].dayWhenProductCreate.day;
			file >> arrayOfData[numberOfLines].dayWhenProductCreate.month;
			file >> arrayOfData[numberOfLines].dayWhenProductCreate.year;
			file >> arrayOfData[numberOfLines].workShopNumber;
			file >> arrayOfData[numberOfLines].productName;
			file >> arrayOfData[numberOfLines].numberOfProductsProduced;
			file >> arrayOfData[numberOfLines].responsiblePerson;

			numberOfLines++;
		}
		arrayOfData = resizeArray(size, size - 1, arrayOfData);
	}
	file.close();
	return arrayOfData;
}


void addInArray(ProductInfo*& arrayOfData, int& size) {
	arrayOfData = resizeArray(size, size + 1, arrayOfData);
	cout << "Enter day when this product create: \n";
	cout << "Day: "; cin >> arrayOfData[size].dayWhenProductCreate.day;
	cout << "Month: "; cin >> arrayOfData[size].dayWhenProductCreate.month;
	cout << "Year: "; cin >> arrayOfData[size].dayWhenProductCreate.year;

	cout << "Enter work Shop number: "; cin >> arrayOfData[size].workShopNumber;
	
	cout << "Enter product Name: "; cin >> arrayOfData[size].productName;
	
	cout << "Enter number of product produced: "; cin >> arrayOfData[size].numberOfProductsProduced;

	cout << "Enter resposible person: "; cin >> arrayOfData[size].responsiblePerson;
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

void sorting(ProductInfo*& arrayOfData, int size, int choice) {
	
	/* 1 - sorting by date (int)
	   2 - sorting by workShopNumber (int)
	   3 - sorting by productName (string)
	   4 - sorting by numberOfProductsProduced (int)
	   5 - sorting by responsiblePerson (string)
	
	*/
	
	switch (choice) {
		// TO DO сделать более нормальную сортировку с учётом месяца и дня
		case 1:
			sort(arrayOfData, arrayOfData + size, compByDayWhenProductCreate);
			break;
		
		case 2:
			sort(arrayOfData, arrayOfData + size, compByWorkShopNumber);
			break;
		
		case 3:
			sort(arrayOfData, arrayOfData + size, compByProductName);
			break;

		case 4: 
			sort(arrayOfData, arrayOfData + size, compByNumberOfProductsProduced);
			break;

		case 5: 
			sort(arrayOfData, arrayOfData + size, compByResponsiblePerson);
			break;

	}
}

// make better search
void search(ProductInfo*& array, int size) {
	
}





// будет выводиться таблица элементов с нумерацией и пользователь выбирает
// deletingElement который будет удалять
void deleteElement(ProductInfo*& arrayOfData, int& size, int deletingElement) {
	//нужно придумать как удалять элемент с файла
	
	for (int i = deletingElement - 1; i < size - 1; i++) {
		arrayOfData[i] = arrayOfData[i + 1];
	}
	arrayOfData = resizeArray(size, size - 1, arrayOfData);
}

// TO DO better
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

int day(ProductInfo* array) {
	
}


ProductInfo* IndividualTask(ProductInfo* arrayOfData, Date beginning, Date end, int size) {
	sorting(arrayOfData, size, 1);
	
	int numberOfLines = 1;
	// make better name!!
	ProductInfo* IndividualArray = new ProductInfo[numberOfLines];

	for (int i = 0; i < size; i++) {
		if (arrayOfData[i].dayWhenProductCreate.month) {
			cout << "your an idiot";
		}
	}
}
// you need to complete individual Task

void writeInFile(ProductInfo* arrayOfData, int size) {
	ofstream file;
	file.open("D:\gitHub\CourseWork\CourseWork\CourseWork\data\\productFile.txt", ios::out);
	for (int i = 0; i < size; i++) {
		file << arrayOfData[i].dayWhenProductCreate.day << " ";
		file << arrayOfData[i].dayWhenProductCreate.month << " ";
		file << arrayOfData[i].dayWhenProductCreate.year << " ";
		file << arrayOfData[i].numberOfProductsProduced << " ";
		file << arrayOfData[i].productName << " ";
		file << arrayOfData[i].responsiblePerson << " ";
		file << arrayOfData[i].workShopNumber << endl;
	}
	file.close();
	delete[] arrayOfData;
}