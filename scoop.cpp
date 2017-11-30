#include "scoop.h"
#include <string>
#include <iostream>

using namespace std;

string Scoop::to_string() {
   string output = _flavor + " " + "Description: " + _description + " " + "Wholesale: $" + std::to_string(_wholesale) + " Retail: $" + std::to_string(_retail) + " Stock Remaining: " + std::to_string(_stock) ;
   return output;
}
void Scoop::consume_stock(int used) {_stock -= used;}
string Scoop::flavor() {return _flavor;}
string Scoop::description() {return _description;}
double Scoop::wholesale() {return _wholesale;}
double Scoop::retail() {return _retail;}
int Scoop::stock() {return _stock;}
