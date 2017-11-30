#include "view.h"
#include "dialogs.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int View::select_from_menu() {
  string menu = R"(
=================================
	     M.I.C.E
=================================

Items
-----
(1) Add Ice Cream Flavor
(2) Add Containers
(3) Add Toppings
(4) List all Inventory

Serving
-------
(5) Make Serving
(6) List Serving

Utility
-------
(9) Help
(0) Exit

)";

  string result = Dialogs::input(menu, "Main Menu");
  try {
    return (result == "CANCEL") ? 0 : stoi(result);
  } catch (...) {
    return -1;
  }
}

string View::get_flavor() {
  string flavor = "";
  int i;
  for (i=0; i< emp.number_of_scoop(); ++i) {
    flavor += std::to_string(i) + ") " + emp.scoop_to_string(i) + "\n";
  }
  return flavor;
}

string View::get_container() {
  string container = "";
  int i;
  for (i=0; i< emp.number_of_containers(); ++i) {
    container += std::to_string(i) + ") " + emp.containers_to_string(i) + "\n";
  }
  return container;
}

string View::get_topping() {
  string topping = "";
  int i;
  for (i=0; i< emp.number_of_toppings(); ++i) {
    topping += std::to_string(i) + ") " + emp.toppings_to_string(i) + "\n" ;
  }
  return topping;
}

string View::get_toppingamount() {
  string amount = R"(
Topping Amount
------------------------------
0) light 
1) normal 
2) extra 
3) drenched
)";
  return amount; 
}

string View::get_inventory() {
  string inventory = "";
  inventory += R"(
Flavors
---------------------------------
)" + get_flavor() + R"(
Containers
---------------------------------
)" + get_container() + 
R"(
Toppings
---------------------------------
)" + get_topping();
  return inventory;
}
string View::get_serving() {
  string serving = "";
  int i;
  for (int i=0; i< emp.number_of_serving(); ++i) {
    serving += std::to_string(i) + ") " + emp.serving_to_string(i) + "\n";
  }
  return serving;
}
string View::get_person() {
  string output = "";
  int i;
  for (int i=0; i< emp.number_of_person(); ++i) {
    output += std::to_string(i) + ") " + emp.people[i] + "\n";
  }  
  return output;

}

string View::get_order() {
  string output = "";
    output += std::to_string(emp.number_of_order() - 1) + ") " + emp.order[emp.number_of_order() - 1] + "\n";
  return output;
}

string View::get_allorder() {
  string output = "";
  for (int i = 0; i < emp.number_of_order(); i++) {
  output += std::to_string(i) + ") " + emp.order[i] + "\n";
  }
  return output;
}

string View::get_money() {
  string output;
  output += "Spent: $" + std::to_string(emp.spent) + "\n" + "Earning: $" + std::to_string(emp.earning) + "\n" + "Profit: $" + std::to_string(emp.earning - emp.spent) + "\n";
  return output;

}

void View::list_flavor() {
  Dialogs::message(get_flavor(), "List of Flavors");
}
void View::list_container() {
  Dialogs::message(get_container(), "List of Containers");
}
void View::list_topping() {
  Dialogs::message(get_topping(), "List of Toppings");
}
void View::list_inventory() {
  Dialogs::message(get_inventory(), "List of Inventory");
}
void View::list_serving() {
  Dialogs::message(get_serving(), "List of Servings");
}
void View::list_order() {
  Dialogs::message(get_order(), "Your Current Order");
}
void View::list_allorder() {
  Dialogs::message(get_allorder(), "List of Order!");
}
void View::list_person() {
  Dialogs::message(get_person(), "List of Person");
}
void View:: list_money() {
  Dialogs::message(get_money(), "Money Statistic!");
}


int View::select_flavor() {
  string flavor = get_flavor();

  string result = Dialogs::input(flavor, "Select a Flavor");
  try {
    return (result == "CANCEL") ? -1 : stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
}
int View::select_container() {
  string container = get_container();

  string result = Dialogs::input(container, "Select a Container");
  try {
    return (result == "CANCEL") ? -1 : stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
}

int View::select_topping() {
  string topping = get_topping();

  string result = Dialogs::input(topping, "Select a Topping");
  try {
    return (result == "CANCEL") ? -1 : stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
}

int View::select_toppingamount() {
  string amount = get_toppingamount();

  string result = Dialogs::input(amount, "Select a Topping Amount");
  try {
    return (result == "CANCEL") ? -1 : stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
}

int View::select_person() {
  string person = get_person();

  string result = Dialogs::input(person, "Select a Person");
  try {
    return (result == "CANCEL") ? -1 : stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
}

int View::select_serving() {
  string serving = get_serving();

  string result = Dialogs::input(serving, "Select a Serving");
  try {
    return (result == "CANCEL") ? -1 : stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
} 
//REGEX check if user input an integer and not letter/doubles 
int View::select_amount() {
  string serving = "Number of Serving";

  string result = Dialogs::input(serving, "Select a amount of Serving");
  if(result == "CANCEL") {return -1;}
  regex integer{"(\\+|-)?[[:digit:]]+"};
  if(regex_match(result,integer)) {return stoi(result);}
  else {Dialogs::message("invalid entry - please type an integer"); return -1;}
  

/*
  try {
    return (result == "CANCEL") ? -1 : stoi(result);
  } catch (...) {
    Dialogs::message("Invalid entry - please type an integer");
  }
*/

}

void View::help() {
  string help = R"(
The M.I.C.E is currently in development can now view cash register and management. Save and Load file too.

(1) Add Ice Cream Flavor - Allow manager to add flavor ice cream
(2) Add Containers - Allow manager to add container along with how many scoop it can hold.
(3) Add Toppings - Allow manager to add toppings.
(4) List all Inventory - Allow manager to view the list of flavor,container, and toppings.
(5) Add Serving - Allow server or manager to create serving for the customer.
(6) List all Serving - Allow manager or server to view the Servings.
(7) Add Customer - Server create a customer.
(8) Add Server - Manager hire server.
(9) Add Order - allow server or customer to make an order from list of servings and choose amount.
(10) File-> Save - Save data file.
(11) File-> Load - load a previous data from file.
(12) Management->Money Statistic - view the business of emporium.
(0) File Quit - Terminate program and data will not save.
Use the '99' command to pre-populate test data.
  )";
  Dialogs::message(help, "Help");
}

