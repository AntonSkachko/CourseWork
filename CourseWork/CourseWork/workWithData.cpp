#include "workWithData.h"

ProductInfo* resizeArray(int& oldSize, int newSize, ProductInfo*& arrayOfProduct) {
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

// чтение файла с продукцией
void readProductFile(ProductInfo*& arrayOfProduct, int& size) {

	const string NAME_OF_PRODUCT_FILE = "productFile.txt";
	ifstream file(NAME_OF_PRODUCT_FILE);

	if (!file.is_open()) {
		cout << " У нас проблемы базой данных продукта" << endl;
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
			file >> arrayOfProduct[numberOfLines].responsiblePerson;
			file >> arrayOfProduct[numberOfLines].numberOfProductsProduced;

			numberOfLines++;
		}
		--size;
	}
	file.close();
}


void addInArray(ProductInfo*& arrayOfProduct, int& size) {
	arrayOfProduct = resizeArray(size, size + 1, arrayOfProduct);
	cout << " Введите дату когда продукт был изготовлен: \n";
	cout << "	день: "; cin >> arrayOfProduct[size - 1].dayWhenProductCreate.day;
	cout << "	месяц: "; cin >> arrayOfProduct[size - 1].dayWhenProductCreate.month;
	cout << "	год: "; cin >> arrayOfProduct[size - 1].dayWhenProductCreate.year;

	cout << " Введите номер цеха: "; cin >> arrayOfProduct[size - 1].workShopNumber;
	
	cout << " Введите название продукта: "; cin >> arrayOfProduct[size - 1].productName;
	
	cout << " Введите количество выпущенных единиц: "; cin >> arrayOfProduct[size - 1].numberOfProductsProduced;

	cout << " Введите имя ответвенного во время производва: "; cin >> arrayOfProduct[size - 1].responsiblePerson;
}


// компоратор для сортирвки по дню
bool compByDayWhenProductCreate(ProductInfo& begin, ProductInfo& end) {
	return begin.dayWhenProductCreate.day < end.dayWhenProductCreate.day;
}

// компоратор для сортирвки по номеру цеха
bool compByWorkShopNumber(ProductInfo& begin, ProductInfo& end) {
	return begin.workShopNumber < end.workShopNumber;
}

// компоратор для сортирвки по количеству продукта
bool compByNumberOfProductsProduced(ProductInfo& begin, ProductInfo& end) {
	return begin.numberOfProductsProduced < end.numberOfProductsProduced;
}

// функция сортировки
void sorting(ProductInfo* arrayOfProduct, int size, int choiceOfSorting) {
	/* 1 - sorting by date (int)
	   2 - sorting by workShopNumber (int)
	   3 - sorting by numberOfProductsProduced (int)	
	*/

	enum CHOICE_OF_SORTING {
		EXIT,
		BY_DAY,
		BY_WORK_SHOP,
		BY_NUMBER_OF_PRODUCT_PRODUCED
	};

	switch (choiceOfSorting) {
		// сортировка по дню
		case BY_DAY:
			sort(arrayOfProduct, arrayOfProduct + size, compByDayWhenProductCreate);
			break;
		
		// сортировка по номеру цеха
		case BY_WORK_SHOP:
			sort(arrayOfProduct, arrayOfProduct + size, compByWorkShopNumber);
			break;
		
		// сортировка по количеству продукта
		case BY_NUMBER_OF_PRODUCT_PRODUCED:
			sort(arrayOfProduct, arrayOfProduct + size, compByNumberOfProductsProduced);
			break;

		// выход
		case EXIT:
			return;
	}
}


// поиск по году когда он произведён
ProductInfo* searchByDayWhenProductCreate(ProductInfo* arrayOfProduct, int size, int& sizeOfTempArray, int date) {
	ProductInfo* tempArray = new ProductInfo[sizeOfTempArray];

	for (int numberOfProduct = 0; numberOfProduct < size; numberOfProduct++) {
		if (arrayOfProduct[numberOfProduct].dayWhenProductCreate.year == date) {
			tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray + 1, tempArray);
			tempArray[sizeOfTempArray - 2] = arrayOfProduct[numberOfProduct];
		}
	}
	tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray - 1, tempArray);
	return tempArray;
}

// поиск по номеру цеха
ProductInfo* searchByWorkShopNumber(ProductInfo* arrayOfProduct, int size, int& sizeOfTempArray, int element) {
	ProductInfo* tempArray = new ProductInfo[sizeOfTempArray];

	for (int numberOfProduct = 0; numberOfProduct < size; numberOfProduct++) {
		if (arrayOfProduct[numberOfProduct].workShopNumber == element) {
			tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray + 1, tempArray);
			tempArray[sizeOfTempArray - 2] = arrayOfProduct[numberOfProduct];
		}
	}
	tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray - 1, tempArray);
	return tempArray;
}

// поиск по имени продукта
ProductInfo* searchByProductName(ProductInfo* arrayOfProduct, int size, int& sizeOfTempArray, string nameOfProduct) {
	ProductInfo* tempArray = new ProductInfo[sizeOfTempArray];

	for (int numberOfProduct = 0; numberOfProduct < size; numberOfProduct++) {
		if (arrayOfProduct[numberOfProduct].productName == nameOfProduct) {
			tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray + 1, tempArray);
			tempArray[sizeOfTempArray - 2] = arrayOfProduct[numberOfProduct];
		}
	}
	tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray - 1, tempArray);
	return tempArray;
}

// поиск по количеству выпущенных единиц
ProductInfo* searchByNumberOfProductsProduced(ProductInfo* arrayOfProduct, int size, int& sizeOfTempArray, int count) {
	ProductInfo* tempArray = new ProductInfo[sizeOfTempArray];

	for (int numberOfProduct = 0; numberOfProduct < size; numberOfProduct++) {
		if (arrayOfProduct[numberOfProduct].numberOfProductsProduced == count) {
			tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray + 1, tempArray);
			tempArray[sizeOfTempArray - 2] = arrayOfProduct[numberOfProduct];
		}
	}
	tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray - 1, tempArray);
	return tempArray;
}

// поиск по ответсвенному в это дату выпуска продукции
ProductInfo* searchByResponsiblePerson(ProductInfo* arrayOfProduct, int size, int& sizeOfTempArray, string person) {
	ProductInfo* tempArray = new ProductInfo[sizeOfTempArray];

	for (int numberOfProduct = 0; numberOfProduct < size; numberOfProduct++) {
		if (arrayOfProduct[numberOfProduct].responsiblePerson == person) {
			tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray + 1, tempArray);
			tempArray[sizeOfTempArray - 2] = arrayOfProduct[numberOfProduct];
		}
	}
	tempArray = resizeArray(sizeOfTempArray, sizeOfTempArray - 1, tempArray);
	return tempArray;
}


// будет выводиться таблица элементов с нумерацией и пользователь выбирает
// deletingElement который будет удалять
void deleteElement(ProductInfo*& arrayOfProduct, int& size, int deletingElement) {
	for (int i = deletingElement; i < size - 1; i++) {
		arrayOfProduct[i] = arrayOfProduct[i + 1];
	}
	size--;
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

ProductInfo* OutputOfNumberOfManufacturedProducts(ProductInfo* arrayOfProduct, Date beginning, Date end, int numberOfWorkshop, int size, int &sizeOfManufacturedProduct) {
	sizeOfManufacturedProduct = 1;
	ProductInfo* manufacturedProducts = new ProductInfo[sizeOfManufacturedProduct];

	for (int i = 0; i < size; i++) {
		if (arrayOfProduct[i].workShopNumber == numberOfWorkshop) {
			if (convertToDay(arrayOfProduct[i].dayWhenProductCreate) >= convertToDay(beginning) &&
				convertToDay(arrayOfProduct[i].dayWhenProductCreate) <= convertToDay(end)) {
				manufacturedProducts[sizeOfManufacturedProduct - 1] = arrayOfProduct[i];
				
				manufacturedProducts = resizeArray(sizeOfManufacturedProduct, sizeOfManufacturedProduct + 1, manufacturedProducts);
			}
		}
	}
	sizeOfManufacturedProduct--;
	return manufacturedProducts;
}


void writeInFile(ProductInfo* arrayOfProduct, int size) {
	ofstream file("productFile.txt");
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

void editProduct(ProductInfo*& arrayOfProduct, int indexOfData, int choice) {
	// indexOfData - номер изменяемого продукта
	// choice - что именно мы изменяем
	/*
		1 - изменение дня производства
		2 - изменение номера цеха
		3 - изменение названия продукта
		4 - изменение количества продукта
		5 - изменение ответвенного за производство продукта
		0 - выход

	*/
	enum CHOICE
	{
		EXIT,
		ENTER_DATA,
		ENTER_WORKSHOP_NUMBER,
		ENTER_PRODUCT_NAME,
		ENTER_NUMBER_OF_PRODUCT_PRODUCED,
		ENTER_RESPONSIBLE_PERSON,

	};
	switch (choice) {
		case ENTER_DATA:
			cout << " Введите новую дату:\n"
			     << "	день: ";
			cin >> arrayOfProduct[indexOfData].dayWhenProductCreate.day;
			
			cout << "	месяц: ";
			cin >> arrayOfProduct[indexOfData].dayWhenProductCreate.month;

			cout << "	год: ";
			cin >> arrayOfProduct[indexOfData].dayWhenProductCreate.year;

			break;

		case ENTER_WORKSHOP_NUMBER:
			cout << " Введите новый номер цеха: ";
			cin >> arrayOfProduct[indexOfData].workShopNumber;
			break;
		
		case ENTER_PRODUCT_NAME:
			cout << " Введите новое название продукта: ";
			cin >> arrayOfProduct[indexOfData].productName;
			break;

		case ENTER_NUMBER_OF_PRODUCT_PRODUCED:
			cout << " Введите новое количество продукта: ";
			cin >> arrayOfProduct[indexOfData].numberOfProductsProduced;
			break;

		case ENTER_RESPONSIBLE_PERSON:
			cout << " Введите новое имя ответсвенного за этот цех";
			cin >> arrayOfProduct[indexOfData].responsiblePerson;
			break;

		case EXIT:
			return;

		default:
			cout << " Введите корректное число!!\n";
			break;
	}
}
