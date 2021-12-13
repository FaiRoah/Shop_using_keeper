#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Purchase
{
private:
	string name;
	int countOf;
	double price;
	double amountPrice;


public:
	Purchase(const Purchase&);
	Purchase(string name, int amount, double price, double amountPrice);
	Purchase();
	string getName();
	void setName(string name);
	double getPrice();
	void setPrice(double price);
	int getCount();
	void setCount(int countOf);
	double getAmount();
	void setAmount(double amountPrice);
	virtual void printInfo() = 0;

};

