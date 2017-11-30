#include "controller.h"
#include "view.h"
#include "emporium.h"
#include "scoop.h"
#include "containers.h"
#include "toppings.h"
#include "serving.h"
#include "dialogs.h"
#include "person.h"
#include "customer.h"
#include "server.h"
#include "manager.h" 
#include <iostream>
#include <string>

using namespace std;

void Controller::cli() {
  int cmd = -1;
  while (cmd != 0) {
    cmd = view.select_from_menu();
    execute_cmd(cmd);
  }
}

void Controller::execute_cmd(int cmd) {


switch(cmd) {

//add flavor
   case(1) :  {
   string flavor, description, whole, retail, stock;
   bool cancel = false;

   Gtk::Dialog *dialog = new Gtk::Dialog();
   dialog->set_title("Create Flavor!");

    Gtk::HBox b_flavor;
    
    Gtk::Label l_flavor{"Flavor:"};
    l_flavor.set_width_chars(15);
    b_flavor.pack_start(l_flavor, Gtk::PACK_SHRINK);

    Gtk::Entry e_flavor;
    e_flavor.set_max_length(50);
    b_flavor.pack_start(e_flavor, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_flavor, Gtk::PACK_SHRINK);

    Gtk::HBox b_desc;
    
    Gtk::Label l_desc{"Description:"};
    l_desc.set_width_chars(15);
    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);

    Gtk::Entry e_desc;
    e_desc.set_max_length(50);
    b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);

    Gtk::HBox b_whole;
    
    Gtk::Label l_whole{"Wholesale:"};
    l_whole.set_width_chars(15);
    b_whole.pack_start(l_whole, Gtk::PACK_SHRINK);

    Gtk::Entry e_whole;
    e_whole.set_max_length(50);
    b_whole.pack_start(e_whole, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_whole, Gtk::PACK_SHRINK);

    Gtk::HBox b_retail;
    
    Gtk::Label l_retail{"Retail:"};
    l_retail.set_width_chars(15);
    b_retail.pack_start(l_retail, Gtk::PACK_SHRINK);

    Gtk::Entry e_retail;
    e_retail.set_max_length(50);
    b_retail.pack_start(e_retail, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_retail, Gtk::PACK_SHRINK);

    Gtk::HBox b_stock;
    
    Gtk::Label l_stock{"Stock:"};
    l_stock.set_width_chars(15);
    b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);

    Gtk::Entry e_stock;
    e_stock.set_max_length(50);
    b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    flavor = e_flavor.get_text();
    description = e_desc.get_text();
    whole = e_whole.get_text();
    retail = e_retail.get_text();
    stock = e_stock.get_text();

    if (result == 1)    {emp.add_scoop(Scoop(flavor, description, stod(whole), stod(retail), stoi(stock)));}
}

   break;


   case(2) : {

   string container, scoop, description, whole, retail, stock;
/*   cout << "Enter Containers name-->";
   getline(cin, containers);
   cout << "Enter integer for Maximum scoops-->";
   getline(cin, size);
   cout << "Enter description-->";
   getline(cin, description);
   cout << "Enter wholesale price-->";
   getline(cin, whole);
   cout << "Enter retail price-->";
   getline(cin, retail);
   cout << "Enter number of stock-->";
   getline(cin, stock);
   emp.add_containers(Containers(container, stoi(size), description, stoi(whole), stoi(retail), stoi(stock)));
*/
   bool cancel = false;

   Gtk::Dialog *dialog = new Gtk::Dialog();
   dialog->set_title("Create Container!");

    Gtk::HBox b_container;
    
    Gtk::Label l_container{"Container:"};
    l_container.set_width_chars(15);
    b_container.pack_start(l_container, Gtk::PACK_SHRINK);

    Gtk::Entry e_container;
    e_container.set_max_length(50);
    b_container.pack_start(e_container, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);

    Gtk::HBox b_desc;
    
    Gtk::Label l_desc{"Description:"};
    l_desc.set_width_chars(15);
    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);

    Gtk::Entry e_desc;
    e_desc.set_max_length(50);
    b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);

    Gtk::HBox b_whole;
    
    Gtk::Label l_whole{"Wholesale:"};
    l_whole.set_width_chars(15);
    b_whole.pack_start(l_whole, Gtk::PACK_SHRINK);

    Gtk::Entry e_whole;
    e_whole.set_max_length(50);
    b_whole.pack_start(e_whole, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_whole, Gtk::PACK_SHRINK);

    Gtk::HBox b_retail;
    
    Gtk::Label l_retail{"Retail:"};
    l_retail.set_width_chars(15);
    b_retail.pack_start(l_retail, Gtk::PACK_SHRINK);

    Gtk::Entry e_retail;
    e_retail.set_max_length(50);
    b_retail.pack_start(e_retail, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_retail, Gtk::PACK_SHRINK);

    Gtk::HBox b_stock;
    
    Gtk::Label l_stock{"Stock:"};
    l_stock.set_width_chars(15);
    b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);

    Gtk::Entry e_stock;
    e_stock.set_max_length(50);
    b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);

    Gtk::HBox b_scoop;
    
    Gtk::Label l_scoop{"Max Scoop:"};
    l_scoop.set_width_chars(15);
    b_scoop.pack_start(l_scoop, Gtk::PACK_SHRINK);

    Gtk::Entry e_scoop;
    e_scoop.set_max_length(50);
    b_scoop.pack_start(e_scoop, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_scoop, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    container = e_container.get_text();
    description = e_desc.get_text();
    whole = e_whole.get_text();
    retail = e_retail.get_text();
    stock = e_stock.get_text();
    scoop = e_scoop.get_text();

   if (result == 1) {emp.add_containers(Containers(container, stoi(scoop), description, stod(whole), stod(retail), stoi(stock))); }
}
   break;


   case(3) : {
   string topping, description, whole, retail, stock;
/*
   cout << "Enter toppings name-->";
   getline(cin, toppings);
   cout << "Enter description-->";
   getline(cin, description);
   cout << "Enter wholesale price-->";
   getline(cin, whole);
   cout << "Enter retail price-->";
   getline(cin, retail);
   cout << "Enter number of stock-->";
   getline(cin, stock);
   emp.add_toppings(Toppings(topping, description, stoi(whole), stoi(retail), stoi(stock))); 
*/
   bool cancel = false;

   Gtk::Dialog *dialog = new Gtk::Dialog();
   dialog->set_title("Create Topping!");

    Gtk::HBox b_topping;
    
    Gtk::Label l_topping{"Topping:"};
    l_topping.set_width_chars(15);
    b_topping.pack_start(l_topping, Gtk::PACK_SHRINK);

    Gtk::Entry e_topping;
    e_topping.set_max_length(50);
    b_topping.pack_start(e_topping, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_topping, Gtk::PACK_SHRINK);

    Gtk::HBox b_desc;
    
    Gtk::Label l_desc{"Description:"};
    l_desc.set_width_chars(15);
    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);

    Gtk::Entry e_desc;
    e_desc.set_max_length(50);
    b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);

    Gtk::HBox b_whole;
    
    Gtk::Label l_whole{"Wholesale:"};
    l_whole.set_width_chars(15);
    b_whole.pack_start(l_whole, Gtk::PACK_SHRINK);

    Gtk::Entry e_whole;
    e_whole.set_max_length(50);
    b_whole.pack_start(e_whole, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_whole, Gtk::PACK_SHRINK);

    Gtk::HBox b_retail;
    
    Gtk::Label l_retail{"Retail:"};
    l_retail.set_width_chars(15);
    b_retail.pack_start(l_retail, Gtk::PACK_SHRINK);

    Gtk::Entry e_retail;
    e_retail.set_max_length(50);
    b_retail.pack_start(e_retail, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_retail, Gtk::PACK_SHRINK);

    Gtk::HBox b_stock;
    
    Gtk::Label l_stock{"Stock:"};
    l_stock.set_width_chars(15);
    b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);

    Gtk::Entry e_stock;
    e_stock.set_max_length(50);
    b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    topping = e_topping.get_text();
    description = e_desc.get_text();
    whole = e_whole.get_text();
    retail = e_retail.get_text();
    stock = e_stock.get_text();

    if (result == 1)    {   emp.add_toppings(Toppings(topping, description, stod(whole), stod(retail), stoi(stock))); }

}
   break;

   case(4) :
   view.list_inventory();
   break;

   case(6) :
   view.list_serving();
   break;

   case(11) : {
   string name, phone, id;

   bool cancel = false;

   Gtk::Dialog *dialog = new Gtk::Dialog();
   dialog->set_title("Create Customer!");

    Gtk::HBox b_name;
    
    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    Gtk::HBox b_id;
    
    Gtk::Label l_id{"ID#:"};
    l_id.set_width_chars(15);
    b_id.pack_start(l_id, Gtk::PACK_SHRINK);

    Gtk::Entry e_id;
    e_id.set_max_length(50);
    b_id.pack_start(e_id, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);

    Gtk::HBox b_phone;
    
    Gtk::Label l_phone{"Phone Number:"};
    l_phone.set_width_chars(15);
    b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

    Gtk::Entry e_phone;
    e_phone.set_max_length(50);
    b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    name = e_name.get_text();
    phone = e_phone.get_text();
    id = e_id.get_text();
   if (result == 1) {   emp.add_customer(Mice::Customer(name,stoi(id),phone)); }
   
   }
   break;

   case(12) : {
   string name, phone, id, salary;

   bool cancel = false;

   Gtk::Dialog *dialog = new Gtk::Dialog();
   dialog->set_title("Create Server!");

    Gtk::HBox b_name;
    
    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    Gtk::HBox b_id;
    
    Gtk::Label l_id{"ID#:"};
    l_id.set_width_chars(15);
    b_id.pack_start(l_id, Gtk::PACK_SHRINK);

    Gtk::Entry e_id;
    e_id.set_max_length(50);
    b_id.pack_start(e_id, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);

    Gtk::HBox b_phone;
    
    Gtk::Label l_phone{"Phone Number:"};
    l_phone.set_width_chars(15);
    b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

    Gtk::Entry e_phone;
    e_phone.set_max_length(50);
    b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

    Gtk::HBox b_salary;
    
    Gtk::Label l_salary{"Salary:"};
    l_salary.set_width_chars(15);
    b_salary.pack_start(l_salary, Gtk::PACK_SHRINK);

    Gtk::Entry e_salary;
    e_salary.set_max_length(50);
    b_salary.pack_start(e_salary, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_salary, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    name = e_name.get_text();
    phone = e_phone.get_text();
    id = e_id.get_text();
    salary = e_salary.get_text();
   if (result == 1) {   emp.add_server(Mice::Server(name,stoi(id),phone, stod(salary))); }
   
   }
   break;

   case(18) : {
   string name, phone, id, salary;

   bool cancel = false;

   Gtk::Dialog *dialog = new Gtk::Dialog();
   dialog->set_title("Create Manager!");

    Gtk::HBox b_name;
    
    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    Gtk::HBox b_id;
    
    Gtk::Label l_id{"ID#:"};
    l_id.set_width_chars(15);
    b_id.pack_start(l_id, Gtk::PACK_SHRINK);

    Gtk::Entry e_id;
    e_id.set_max_length(50);
    b_id.pack_start(e_id, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);

    Gtk::HBox b_phone;
    
    Gtk::Label l_phone{"Phone Number:"};
    l_phone.set_width_chars(15);
    b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

    Gtk::Entry e_phone;
    e_phone.set_max_length(50);
    b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

    Gtk::HBox b_salary;
    
    Gtk::Label l_salary{"Salary:"};
    l_salary.set_width_chars(15);
    b_salary.pack_start(l_salary, Gtk::PACK_SHRINK);

    Gtk::Entry e_salary;
    e_salary.set_max_length(50);
    b_salary.pack_start(e_salary, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_salary, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    name = e_name.get_text();
    phone = e_phone.get_text();
    id = e_id.get_text();
    salary = e_salary.get_text();
   if (result == 1) {   emp.add_manager(Mice::Manager(name,stoi(id),phone, stod(salary))); }
   
   }
   break;

//STATE MACHINE  create serving,cancel-> create order, cancel -> finish order, view order

//make serving
   case(5) : {

   int container, scoop, topping, amount;
   scoop = view.select_flavor();
   if(scoop == -1) {break;}
   container = view.select_container();
   if(container == -1) {break;}
   topping = view.select_topping();
   if(topping == -1) {break;}
   amount = view.select_toppingamount();
   if(amount == -1) {break;}
   emp.add_serving(container, scoop, topping, amount);
}
//make order
   case(13) : {

   int person,serving, amount;
   person = view.select_person();
   if(person == -1) {break;}
   serving = view.select_serving();
   if(serving == -1) {break;}
   amount = view.select_amount();
   if(amount == -1) {break;}
   emp.add_order(person, amount, serving);
   view.list_order();
}
break;

   case(14) : {
   view.list_money();
}
   break;

   case(15) : {
   string filename;
   filename = Dialogs::input("Example: save.txt", "Input Save File Name");
   emp.savefile(filename);
}
   break;
   
   case(16) : {
   string filename;
   filename = Dialogs::input("Example: save.txt", "Input Load File Name");
   emp.loadfile(filename);
}
   break;

   case(17) :
   view.list_allorder();
   break;

   case(9) :
   view.help();
   break;

   case(0) :
   exit(0);
   break;

   case(99) :
   emp.easter();
   break;

   default :
   cout << "invalid command try again plz\n";
}
//end of switch
}


