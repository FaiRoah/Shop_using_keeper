#pragma once
#include <iostream>
#include "Purchase.h"
using namespace std;
class Product : public Purchase
{
private:
	string name;
	double price;

public:
	Product(string name, double price);
	Product(const Product&);
	void setName(string name);
	void setPrice(double price);
	string getName();
	double getPrice();
	void printInfo(); //prints name and price of a product
	Product();
};

