#define LOWLIMIT 0  //limits for the main menu
#define UPLIMIT 6


#define SHOW 1
#define ADD 2
#define REMOVE 3
#define SAVE 4
#define UPLOAD 5
#define ADDTOCART 6
#define EXIT 0

#define PATH "savingFile.txt"

#include <iostream>
#include <typeinfo>	
#include <conio.h>
#include "Keeper.h"
#include "InputCheck.h"

using namespace std;

void printMenu();

int main() { //dynamic array base** ptr;
    Keeper keeper;
    double wholePrice=0;
    cout << endl << "Hey :)" << endl << endl;
    while (true) {
        printMenu();
        switch (getIntValue(LOWLIMIT, UPLIMIT)) {
            cout << endl;
        case SHOW:
            keeper.showAllInfo();
            cout <<endl << "Price of the whole cart is:";
            for (int i = 0; i < keeper.getSize(); i++) {
                wholePrice += keeper.dataPtr[i]->getAmount();
            }
            cout << wholePrice << endl << endl;
            break;
        case ADD:
            keeper.add(new Product);    //adding a new entity
            cout << endl << "Enter name:";
            keeper.dataPtr[keeper.getSize() - 1]->setName(getStringValue());
            cout << endl << "Enter price:";
            keeper.dataPtr[keeper.getSize() - 1]->setPrice(getDoubleValue(0,10000));
            cout << endl << "Enter count:";
            keeper.dataPtr[keeper.getSize() - 1]->setCount(getIntValue(0,100));
            keeper.dataPtr[keeper.getSize() - 1]->setAmount(keeper.dataPtr[keeper.getSize() - 1]->getPrice() * keeper.dataPtr[keeper.getSize() - 1]->getCount());            break;
        case REMOVE:
            if (keeper.isEmpty()) {
                cout << endl << "The array is empty. Nothing to remove..." << endl << endl;
                break;
            }
            else {
                cout << "Here are all products:" << endl;
                keeper.showAllInfo();
                cout << "What entity you want to remove? Enter a number:";
                keeper.remove(keeper.dataPtr[getIntValue(1, keeper.getSize()) - 1]);
                break;
            }
        case SAVE:
            if (keeper.isEmpty()) {
                cout << endl << "The array is empty. Nothing to save..." << endl << endl;
                break;
            }
            else {
                keeper.saveData(PATH);
                cout << endl << "Successful saving data" << endl << endl;
                break;
            }
        case UPLOAD:
            keeper.uploadData(PATH);
            cout << endl << "Successful uploading data" << endl << endl;
            break;
        case EXIT:
            /*while (true) {
                cout << endl << "Confirm exiting. y/n:";
                _getch()
            }*/
            cout << endl << "Exiting the program. Bye-bye." << endl << endl;
            return 0;
        default:
            cout << endl << "Wrong number entered." << endl;
            break;
        }
    }
    return 0;
}

void printMenu() {
    cout << "What do you want to do:" << endl;
    cout << "1. Show your cart" << endl <<
        "2. Add a product to your cart" << endl <<
        "3. Remove a product from your cart" << endl <<
        "4. Save data to file" << endl <<
        "5. Upload data from file" << endl <<
        "0. Exit the program" << endl << endl <<
        "Enter a number:";
}

