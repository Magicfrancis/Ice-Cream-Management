#ifndef __TOPPINGS_H
#define __TOPPINGS_H 

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Toppings {
   public:
     Toppings(string input_toppings, string input_desc, double input_whole, double input_retail, int input_stock) : _toppings(input_toppings), _description(input_desc), _wholesale(input_whole), _retail(input_retail), _stock(input_stock){ }

     string to_string();

     string toppings();
     void consume_stock(int used);
     string description();
     double wholesale();
     double retail();
     int stock();
     string topping_amount(int var);

   private:
     string _toppings;
     string _description;
     double _wholesale;
     double _retail;
     int _stock;
     vector <string> amount {"light", "normal", "extra", "drenched"};

};
#endif
