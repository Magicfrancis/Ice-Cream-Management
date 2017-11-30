#include "toppings.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Toppings::to_string() {
   string output = _toppings + " " + "Description: " + _description + " " + "Wholesale: $" + std::to_string(_wholesale) + " Retail: $" + std::to_string(_retail) + " Stock Remaining: " + std::to_string(_stock) ;
   return output;
}

void Toppings::consume_stock(int used) {_stock -= used;}
string Toppings::toppings() {return _toppings;}
string Toppings::description() {return _description;}
double Toppings::wholesale() {return _wholesale;}
double Toppings::retail() {return _retail;}
int Toppings::stock() {return _stock;}
string Toppings::topping_amount(int var){return amount[var];};
