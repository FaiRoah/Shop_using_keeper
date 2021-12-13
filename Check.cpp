#include "Check.h"
void Check::printInfo() {

	cout << Purchase::getName() << endl;
	cout << "Price - " << Purchase::getPrice() << endl;
	cout << "Amount- " << Purchase::getCount() << endl;
	cout << "Amount cost - " << Purchase::getAmount() << endl;

}

Check::Check(string name, int amount, double price, double amountPrice)
	:Purchase(name, amount, price, amountPrice) {}


