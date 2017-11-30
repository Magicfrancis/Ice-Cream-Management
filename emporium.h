#ifndef EMPORIUM_H
#define EMPORIUM_H 

#include <string>
#include <functional>
#include <vector>
#include "scoop.h"
#include "containers.h"
#include "toppings.h"
#include "serving.h"
#include "person.h"
#include "server.h"
#include "manager.h"
#include "customer.h"
#include <iostream>
#include <fstream>

using namespace std;

class Emporium {
    public:
       void add_scoop(Scoop var);
       void add_containers(Containers var);
       void add_toppings(Toppings var);
       void add_serving(int container, int scoops, int topping, int amount);
       void add_customer(Mice::Customer var);
       void add_server(Mice::Server var);
       void add_manager(Mice::Manager var);
       string add_order(int person, int amount, int serving);
       string scoop_to_string(int scoop_index);
       string containers_to_string(int containers_index);
       string toppings_to_string(int toppings_index);
       string serving_to_string(int serving_index);
       int number_of_scoop();
       int number_of_containers();
       int number_of_toppings();
       int number_of_serving();
       int number_of_server();
       int number_of_manager();
       int number_of_customer();
       int number_of_order();
       int number_of_person();
       void savefile (string filename);
       void loadfile (string filename);
       void easter();
       double spent =0;
       double earning=0;
       vector<string> order;
       vector<string> people;
    private:
       vector<Mice::Customer> cust;
       vector<Mice::Server> server;
       vector<Mice::Manager> manager;
       vector<Scoop> scoop;
       vector<Containers> containers;
       vector<Toppings> toppings;
       vector<Serving> servings;
       

};
#endif
