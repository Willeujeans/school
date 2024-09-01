/*
Graded on code structure & testbench values
For this assignment you are going to implement a very simple Store interface:
 -The functions and their descriptions are defined in the header file (Store.h).
 -You are to store the inventory(item num and price) into an unordered map defined in the header file and use that map to find and use the prices associated with the item numbers.

You will need the following references to help you with this assignment: -https://www.cplusplus.com/reference/unordered_map/unordered_map/unordered_map/
    -https://www.cplusplus.com/reference/map/map/map/

You may also need to look into fstreams for the file manipulation needed to read in dataList.txt
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Store.h"

using namespace std;

//Constructor Function to initilize an instance of the "Store" class
Store::Store() {
    cartTotal = 0.0;
}

void Store::initInventory(std::string dataFile) {
    cout << "initInventory("<< dataFile <<"){" << endl;
    ifstream MyReadFile;
    MyReadFile.open(dataFile,ios::in); //open a file to perform read operation using file object
    if(MyReadFile.is_open()){
        string myText;
        while(getline(MyReadFile, myText)){ //read data from file object and put it into string.
            string priceString = "";
            string keyString = "";
            bool seen_Space = false;
            for(long unsigned int i= 0; i < myText.length(); i++){
                if(seen_Space){
                    priceString += myText[i];
                }else{
                    if(myText[i] != ' '){
                        keyString += myText[i];
                    }
                }
                if(myText[i] == ' ') seen_Space = true;
            }
            int i_key = stoi(keyString);
            float f_price = std::stof(priceString);
            inventory.insert({i_key,f_price});
        }
    }else{
        cout << "!CANNOT OPEN FILE!" << endl;
    }
    cout << " INVENTORY[" << endl;
    for (auto u : inventory){
        cout << "  [" << u.first << "] " << u.second << endl;
    }
    cout << "]" << endl;
    cout << "}returns();" << endl; cout << endl;
}

void Store::clearCart() {
    cout << "ClearCart(){" << endl;
    cartTotal = 0;
    cout << "}returns();" << endl; cout << endl;
}

void Store::addToCart(uint32_t itemNum, uint32_t quantity) {
    cout << "addToCart("<< itemNum << "," << quantity << "){" << endl;
    float itemCost = inventory.at(itemNum);
    cout << " Item[" << itemNum << "] $" << itemCost << " * " << quantity << " = " << itemCost*quantity << endl;
    cartTotal += itemCost * quantity;
    cout << " cartTotal = $" << cartTotal << endl;
    cout << "}returns();" << endl;cout << endl;
}

float Store::getCost(uint32_t itemNum) {
    cout << "getCost(" << itemNum << "){" << endl;
    float itemCost = inventory.at(itemNum);
   cout << "}returns(" << itemCost << ");" << endl; cout << endl;
   return itemCost;
}

float Store::getTotal() {
   cout << endl;
   cout << "getTotal(){" << endl;
   cout << "}returns(" << cartTotal << ");" << endl; cout << endl;
   return cartTotal;
}
