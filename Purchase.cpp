#include "Purchase.h"

Purchase::Purchase(const Purchase& b) {
	name = b.name;
	price = b.price;
	amountPrice = b.amountPrice;
	countOf = b.countOf;
}

Purchase::Purchase(string name, int countOf, double price, double amountPrice) {
	this->name = name;
	this->price = price;
	this->amountPrice = amountPrice;
	this->countOf = countOf;
}

Purchase::Purchase() {

}


void Purchase::setName(string name) {
	this->name = name;
}

void Purchase::setPrice(double price) {
	this->price = price;
}

void Purchase::setAmount(double amountPrice) {
	this->amountPrice = amountPrice;
}

void Purchase::setCount(int count) {
	this->countOf = count;
}

string Purchase::getName() {
	return name;
}

double Purchase::getPrice() {
	return price;
}

double Purchase::getAmount() {
	return amountPrice;
}

int Purchase::getCount() {
	return countOf;
}

