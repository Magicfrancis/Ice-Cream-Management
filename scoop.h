#ifndef __SCOOP_H
#define __SCOOP_H 

#include <iostream>
#include <string>

using namespace std;


class Scoop {
   public:
    Scoop(string input_flavor, string input_desc, double input_whole, double input_retail, int input_stock) : _flavor(input_flavor), _description(input_desc), _wholesale(input_whole), _retail(input_retail), _stock(input_stock) { }

    string to_string();
     void consume_stock(int used);
    string flavor();
    string description();
    double wholesale();
    double retail();
    int stock();

   private:
    string _flavor;
    string _description;
    double _wholesale;
    double _retail;
    int _stock;

};
#endif
