//============================================================================
// Name        :
// Author      : Bonnie Bell
// Version     :
// Copyright   : Your copyright notice
// Description : Hash Table
//============================================================================
//READ ONLY
#include <fstream>
#include <unordered_map>
#include <string>
#include <iostream>
#include "Store.h"
using namespace std;

int main() {
   //Create an iteration of the class "Store" with no arguments
   Store myStore;
   
   //we are initilizing the inventory based on this dataList.txt
   myStore.initInventory("dataList.md");
    
   //Adding an inventory item to the cart, giving it an amount
   myStore.addToCart(1,4);
   myStore.addToCart(5,3);
    
   //getTotal will look at the items missing and calculate the value of the cart
   if (abs(myStore.getTotal() - 101.90) < .001) {
      cout << "Cart total is correct!" << endl;
   }else{
      cout << "Cart total expected $101.90 actual: " << myStore.getTotal();
   }
}
