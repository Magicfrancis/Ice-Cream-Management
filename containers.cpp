#include "containers.h"
#include <iostream>
#include <string>

using namespace std;

string Containers::to_string() {
   string output = _containers + "(" + std::to_string(_hold) + " scoop) " + "Description: " + _description + " " +"Wholesale: $" + std::to_string(_wholesale) + " Retail: $" + std::to_string(_retail) + " Stock Remaining: " + std::to_string(_stock) ;
   return output;
}
void Containers::consume_stock(int used) {_stock -= used;}
string Containers::containers() {return _containers;}
int Containers::hold() {return _hold;}
string Containers::description() {return _description;}
double Containers::wholesale() {return _wholesale;}
double Containers::retail() {return _retail;}
int Containers::stock() {return _stock;}
