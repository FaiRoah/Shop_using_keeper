#pragma once
#include "Purchase.h"

class Check : public Purchase
{
	Check(string name, int amount, double price, double amountPrice);
	virtual void printInfo();
};

