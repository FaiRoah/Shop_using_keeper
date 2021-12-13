#include "Keeper.h"

void Keeper::add(Purchase* basePtr)
{
	Purchase** tmp = Keeper::dataPtr;
	Keeper::size++;
	dataPtr = new Purchase * [Keeper::size];
	for (int i = 0; i < size - 1; i++)
		dataPtr[i] = tmp[i];
	dataPtr[Keeper::size - 1] = basePtr;	//adding new entity to the end of the array

}

void Keeper::remove(Purchase* basePtr) {
	Purchase** tmp = Keeper::dataPtr;
	Keeper::size--;
	dataPtr = new Purchase * [Keeper::size];
	for (int i = 0; i <= size; i++) {	//"i <= size" because i have to check all elements of the initial array
		if (tmp[i] != basePtr) {
			dataPtr[i] = tmp[i];
		}
		else {
			i++;
			for (int j = i - 1; i <= size; j++, i++)
				dataPtr[j] = tmp[i];
			break;
		}
	}
	delete basePtr;
	cout << endl << "The element has been removed" << endl << endl;
}

void Keeper::showAllInfo() {
	if (size == 0)		//array is empty
		cout << endl << "The array is empty. Nothing to show for now..." << endl << endl;
	else
		for (int i = 0; i < size; i++) {
			cout << endl << "~~~~~~~~~~~~~~~~~~" << endl;
			cout << i + 1 << "." << endl;
			cout << "Name: " << dataPtr[i]->getName() << endl;
			cout << "Price: " << dataPtr[i]->getPrice() << endl;
			cout << "Count: " << dataPtr[i]->getCount() << endl;
			cout << "Price for the whole amount: " << dataPtr[i]->getAmount() << endl;

			cout << "~~~~~~~~~~~~~~~~~~" << endl << endl;
		}
}


void Keeper::saveData(const char* path)
{
	fstream file;
	file.exceptions(ofstream::badbit | ofstream::failbit);
	try {
		file.open(path, std::fstream::out | std::fstream::trunc);
	}
	catch (const ofstream::failure& ex) {
		cout << "Error occured while opening the file." << endl;
		cout << ex.what() << endl << ex.code() << endl;
	}
	file << Keeper::size << endl << endl;			
	for (int i = 0; i < size; i++) {
		file << "PRODUCT" << endl;
		file << "name:";
		file << dataPtr[i]->getName() << endl;		
		file << "price:";
		file << dataPtr[i]->getPrice() << endl;
		file << "count:";
		file << dataPtr[i]->getCount() << endl;
		file << "amount:";
		file << dataPtr[i]->getAmount() << endl;
		file << endl;
	}
	file.close();
}

void Keeper::uploadData(const char* path) {
	fstream file;			//file to upload from
	string entityBuffer;	//buffer to define which entity to create: MONSTER, GOOD or EVIL
	string fieldBuffer[5];	//buffer to define fields of each entity. 5 is the biggest amount of fields of an entity
	string buf;				//buffer to skip empty line breaker
	file.exceptions(ifstream::badbit);
	try {
		file.open(path);
	}
	catch (const ifstream::failure& ex) {
		cout << "Error occured while opening the file." << endl;
		cout << ex.what() << endl << ex.code() << endl;
	}
	if (!Keeper::isEmpty()) {
		int prevArrSize = Keeper::getSize();	//size of the array that needs to be removed
		for (int i = 0; i < prevArrSize; i++)
			Keeper::remove(dataPtr[0]);		//removing 0th element every time because Keeper::remove() moves elements to the left by 1
	}

	while (!file.eof()) {
		getline(file, buf);
		if (buf == "PRODUCT") {
			getline(file, buf);
			if (
				(buf[0] == 'n') &&
				(buf[1] == 'a') &&
				(buf[2] == 'm') &&
				(buf[3] == 'e') &&
				(buf[4] == ':')
				) {
				fieldBuffer[0].assign(buf.begin() + 5, buf.end());
			}
			else {
				cout << "name of the PRODUCT not found. Input a name of the PRODUCT:";
				fieldBuffer[0] = getStringValue();
			}
			getline(file, buf);
			if (
				(buf[0] == 'p') &&
				(buf[1] == 'r') &&
				(buf[2] == 'i') &&
				(buf[3] == 'c') &&
				(buf[4] == 'e') &&
				(buf[5] == ':')
				) {
				fieldBuffer[1].assign(buf.begin() + 6, buf.end());
			}
			else {
				cout << "Price of the PRODUCT not found. Input a price of the PRODUCT:";
				fieldBuffer[1] = getStringValue();
			}
			getline(file, buf);
			if (
				(buf[0] == 'c') &&
				(buf[1] == 'o') &&
				(buf[2] == 'u') &&
				(buf[3] == 'n') &&
				(buf[4] == 't') &&
				(buf[5] == ':')
				) {
				fieldBuffer[2].assign(buf.begin() + 6, buf.end());
			}
			else {
				cout << "Count of the PRODUCT not found. Input a count of the PRODUCT:";
				fieldBuffer[2] = getStringValue();
			}
			getline(file, buf);
			if (
				(buf[0] == 'a') &&
				(buf[1] == 'm') &&
				(buf[2] == 'o') &&
				(buf[3] == 'u') &&
				(buf[4] == 'n') &&
				(buf[5] == 't') &&
				(buf[6] == ':')
				) {
				fieldBuffer[3].assign(buf.begin() + 7, buf.end());
			}
			else {
				cout << "Price of the amount of the PRODUCT not found. Input a price of the amount of the PRODUCT:";
				fieldBuffer[3] = getStringValue();
			}
			Keeper::add(new Product);    //adding a new entity
			dataPtr[getSize() - 1]->setName(fieldBuffer[0]);
			dataPtr[getSize() - 1]->setPrice(stod(fieldBuffer[1], (size_t*)nullptr));
			dataPtr[getSize() - 1]->setCount(stod(fieldBuffer[2], (size_t*)nullptr));
			dataPtr[getSize() - 1]->setAmount(stod(fieldBuffer[3], (size_t*)nullptr));

		}

	}
	file.close();
}

bool Keeper::isEmpty()
{
	if (Keeper::size > 0)
		return false;
	else
		return true;
}


Keeper::Keeper()
{
	cout << "Keeper's constructor " << this << " is called" << endl;
	size = 0;
	dataPtr = new Purchase * [size];
}

Keeper::Keeper(const Keeper& other) {
	this->dataPtr = other.dataPtr;
	this->size = other.size;
	cout << "Keeper's copy constructor " << this << " is called" << endl;
}


Keeper::~Keeper() {
	cout << "Keeper's destructor " << this << " is called" << endl;
	for (int i = 0; i < size; i++) {

		delete dataPtr[i];
	}
	dataPtr = nullptr;
	size = 0;
}

int Keeper::getSize()
{
	return Keeper::size;
}
