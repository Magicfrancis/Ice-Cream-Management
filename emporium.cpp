#include "emporium.h"


void Emporium::add_scoop(Scoop var) {
  scoop.push_back(var);
  spent += var.wholesale();
}

void Emporium::add_containers(Containers var) {
  containers.push_back(var);
  spent += var.wholesale();
}

void Emporium::add_toppings(Toppings var) {
  toppings.push_back(var);
  spent += var.wholesale();
}

void Emporium::add_serving(int container, int scoops, int topping, int amount) {
containers[container].consume_stock(1);
scoop[scoops].consume_stock(containers[container].hold());
toppings[topping].consume_stock(amount+1);
servings.push_back(Serving(containers[container], scoop[scoops], toppings[topping], amount));
}

void Emporium::add_customer(Mice::Customer var) {
  cust.push_back(var);
  string output;
  output += "Customer: " + var.name() + "(" + var.phone() + ")";
  people.push_back(output);
}

void Emporium::add_server(Mice::Server var) {
  server.push_back(var);
  string output;
  output += "Server: " + var.name() + "(" + var.phone() + ")";
  people.push_back(output);
}
void Emporium::add_manager(Mice::Manager var) {
  manager.push_back(var);
  string output;
  output += "Manager: " + var.name() + "(" + var.phone() + ")";
  people.push_back(output);
}
string Emporium::add_order(int person, int amount, int serving) {
  string output;
  output += "\nOrder created by " + people[person] + "\nAmount: " + std::to_string(amount) + "\n" + servings[serving].print_serving() + "\nTotal Cost: $" + std::to_string(servings[serving].price() * amount);
  order.push_back(output);
  earning += servings[serving].price() * amount;
  return output; 
}

string Emporium::scoop_to_string(int scoop_index) {
  return scoop[scoop_index].to_string();
}

string Emporium::containers_to_string(int containers_index) {
  return containers[containers_index].to_string();
}

string Emporium::toppings_to_string(int toppings_index) {
  return toppings[toppings_index].to_string();
}

string Emporium::serving_to_string(int serving_index) {
  return servings[serving_index].print_serving();
}

int Emporium::number_of_scoop() {
  return scoop.size();
}

int Emporium::number_of_containers() {
  return containers.size();
}

int Emporium::number_of_toppings() {
  return toppings.size();
}

int Emporium::number_of_serving() {
  return servings.size();
}

int Emporium::number_of_server() {
  return server.size();
}

int Emporium::number_of_manager() {
  return manager.size();
}

int Emporium::number_of_customer() {
  return cust.size();
}

int Emporium::number_of_order() {
  return order.size();
}

int Emporium::number_of_person() {
  return people.size();
}

void Emporium::savefile(string filename) {
  ofstream file;
  file.open(filename);

  for (int i = 0; i < number_of_scoop(); i++)
  {
  //file << scoop[i].get_constructor();
  }
  file << "#\n" ;
  file << "#\n" ;

  file.close();
  return;
}

void Emporium::loadfile(string filename) {
  ifstream file;
  file.open(filename, ifstream::in);
  easter();
  while (true) {
  file.get();
  if (file.eof()) {file.close(); return;}
  }
}

//TEST IF FUNCTIONAL CLASSES
void Emporium::easter() {
  add_scoop(Scoop("Orange Power", "really just orange" , 0.21, 1.80, 22));
  add_scoop(Scoop("Cake Madness", "really just vanilla" , 0.11, 2.50, 632));
  add_scoop(Scoop("Red Velvet", "really just red velvet" , 2.01, 14.50, 2));
  add_containers(Containers("Cone", 1, "really just cone" , 0.01, 1.20, 42));
  add_containers(Containers("Small Bowl", 3, "really just bowl" , 0.41, 2.50, 32));
  add_containers(Containers("Sharing Bowl", 12, "really just bigger bowl" , 0.91, 7.50, 82));
  add_toppings(Toppings("Magic", "real magic" , 0.01, 100.50, 72));
  add_toppings(Toppings("Glitter", "better than Magic" , 0.01, 1000.50, 2));
  add_toppings(Toppings("Gummy Bear", "not made from real bear but gummy" , 0.03, 2.50, 352));
  add_serving(1,1,1,1);
  add_serving(0,0,0,0);
  add_customer(Mice::Customer("Francis Le", 0 , "123-234-2342"));
  add_manager(Mice::Manager("Manly Man", 0 , "123-333-0000",1000));
  add_server(Mice::Server("Bob Dude", 0 , "234-234-2345", 100));
}


