#include "workWithData.h"

ProductInfo* resizeArray(int& oldSize, int newSize, ProductInfo* array) {
	if (oldSize == newSize) {
		return array;
	}
	
	ProductInfo* newArray = new ProductInfo[newSize];
	oldSize = newSize < oldSize ? newSize : oldSize;
	for (int i = 0; i < oldSize; i++) {
		newArray[i] = array[i];
	}
	oldSize = newSize;
	delete[] array;
	return newArray;
}

ProductInfo* readFile(ProductInfo* array, int size) {
	ifstream file;
	file.open("productFile.txt");

	if (!file.is_open()) {
		cout << "We have a problem" << endl;
	}
	else {
		int numberOfLines = 0;
		while (!file.eof()) {
			if (numberOfLines >= size) {
				array = resizeArray(size, size + 1, array);
			}
			file >> array[numberOfLines].dayWhenProductCreate.day;
			file >> array[numberOfLines].dayWhenProductCreate.month;
			file >> array[numberOfLines].dayWhenProductCreate.year;
			file >> array[numberOfLines].workShopNumber;
			file >> array[numberOfLines].productName;
			file >> array[numberOfLines].numberOfProductsProduced;
			file >> array[numberOfLines].responsiblePerson;

			numberOfLines++;
		}
		array = resizeArray(size, size - 1, array);
	}
	file.close();
	return array;
}


void addInFile(ProductInfo temp, int size) {
	ofstream file;
	file.open("productFile.txt");
	
	file << endl << temp.dayWhenProductCreate.day << " ";
	file << temp.dayWhenProductCreate.month << " ";
	file << temp.dayWhenProductCreate.year << " ";
	file << temp.workShopNumber << " ";
	file << temp.productName << " ";
	file << temp.numberOfProductsProduced << " ";
	file << temp.responsiblePerson << endl;

	file.close();
	
}

bool comp(ProductInfo& beg, ProductInfo& sec) {
	return beg.productName < sec.productName;
}


// make better sorting)!!
void sorting(ProductInfo*& array, int size, int choice) {
	/* 1 - sorting by date (int)
	   2 - sorting by workShopNumber (int)
	   3 - sorting by productName (string)
	   4 - sorting by numberOfProductsProduced (int)
	   5 - sorting by responsiblePerson (string)
	
	*/
	
	switch (choice) {
		int temp;
		
		// TO DO сделать более нормальную сортировку с учётом месяца и дня
		case 1:
			for (int i = 0; i < size - 1; i++) {
				for (int j = i; j < size - i - 1; j++) {
				
					if (array[j].dayWhenProductCreate.year > array[j + 1].dayWhenProductCreate.year) {
						
						temp = array[j].dayWhenProductCreate.year;
						array[j].dayWhenProductCreate.year = array[j + 1].dayWhenProductCreate.year;
						array[j + 1].dayWhenProductCreate.year = temp;
						
					}
				}
			}
			break;
	
		case 2:
			for (int i = 0; i < size - 1; i++) {
				for (int j = i; j < size - i - 1; j++) {
					if (array[j].workShopNumber > array[j + 1].workShopNumber) {

						temp = array[j].workShopNumber;
						array[j].workShopNumber = array[j + 1].workShopNumber;
						array[j + 1].workShopNumber = temp;
					}
				}
			}
			break;
		
		// TO DO 3 and 4 with string;
		case 3:
			sort(array, array + size, comp);

		case 4: 
			for (int i = 0; i < size - 1; i++) {
				for (int j = i; j < size - i - 1; j++) {
					if (array[j].numberOfProductsProduced > array[j + 1].numberOfProductsProduced) {
						
						temp = array[j].numberOfProductsProduced;
						array[j].numberOfProductsProduced = array[j + 1].numberOfProductsProduced;
						array[j + 1].numberOfProductsProduced = temp;
					}
				}
			}
	}
}

// make better search
void search(ProductInfo*& array, int size) {
	
}



// будет выводиться таблица элементов с нумерацией и пользователь выбирает
// deletingElement который будет удалять

void deleteElement(ProductInfo*& array, int& size, int deletingElement) {
	//нужно придумать как удалять элемент с файла
	
	for (int i = deletingElement - 1; i < size - 1; i++) {
		array[i] = array[i + 1];
	}
	array = resizeArray(size, size - 1, array);
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


ProductInfo* IndividualTask(ProductInfo* array, Date beginning, Date end, int size) {
	sorting(array, size, 1);
	
	int numberOfLines = 1;
	// make better name!!
	ProductInfo* IndividualArray = new ProductInfo[numberOfLines];

	for (int i = 0; i < size; i++) {
		if(array[i].dayWhenProductCreate.month)
	}
}