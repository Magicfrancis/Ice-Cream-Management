#include "serving.h"

double Serving::price() {
return _containers.retail() + _scoop.retail() + _toppings.retail();}

std::string Serving::print_serving() {
string output; 
output += _scoop.flavor() + " with " + _toppings.topping_amount(_topping_amount) + " " + _toppings.toppings() + " on a " + _containers.containers() + ". Price: $" + std::to_string(price()); 
return output;
}
