#ifndef __SERVING_H
#define __SERVING_H 

#include <string>
#include <functional>
#include <vector>
#include "scoop.h"
#include "containers.h"
#include "toppings.h"

class Serving {

  public:
  
  Serving (Containers& containers, Scoop& scoop, Toppings& toppings, int topping_amount) : _containers(containers), _scoop(scoop), _toppings(toppings), _topping_amount(topping_amount) { }

  std::string print_serving();
  double price();
  
  private:
  
  Containers& _containers;
  Scoop& _scoop;
  Toppings& _toppings;
  int _topping_amount;

};
#endif
