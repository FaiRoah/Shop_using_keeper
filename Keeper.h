#pragma once

#define MONSTER_FIELDS 2
#define GOOD_FIELDS 3
#define EVIL_FIELDS 5
#include <iostream>
#include <fstream>
#include <string>
#include "product.h"
#include "Purchase.h"
#include "InputCheck.h"

using namespace std;

class Keeper
{
private:
	int size;	//size of the dynamic array of pointers
public:
	Purchase** dataPtr;
	void add(Purchase* basePtr);
	void remove(Purchase* basePtr);
	int getSize();	//remember that size starts from 1, all other functions start from 0
	void showAllInfo();
	void saveData(const char* path);
	void uploadData(const char* path);
	bool isEmpty();

	Keeper();
	Keeper(const Keeper& other);
	~Keeper();
};

