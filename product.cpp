#include "product.h"

Product::Product(const Product& a) {
	this->name = a.name;
	this->price = a.price;
}

Product::Product(string name, double price) {
	this->name = name;
	this->price = price;
}

Product::Product() {

}


void Product::setName(string name) {
	this->name = name;
}

void Product::setPrice(double price) {
	this->price = price;
}

string Product::getName() {
	return name;
}

double Product::getPrice() {
	return price;
}
void Product::printInfo() {
	cout << Product::getName() << " - " << Product::getPrice() << endl;
}


