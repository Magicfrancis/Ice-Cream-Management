#ifndef __CONTAINERS_H
#define __CONTAINERS_H 

#include <iostream>
#include <string>

using namespace std;


class Containers {
   public:
     Containers(string input_containers, int input_hold, string input_desc, double input_whole, double input_retail, int input_stock) : _containers(input_containers), _hold(input_hold), _description(input_desc), _wholesale(input_whole), _retail(input_retail), _stock(input_stock) { }

     string to_string();
     string containers();
     int hold();
     void consume_stock(int used);
     string description();
     double wholesale();
     double retail();
     int stock();


   private:
     string _containers;
     int _hold;
     string _description;
     double _wholesale;
     double _retail;
     int _stock;

};
#endif

