#ifndef __VIEW_H
#define __VIEW_H 
 
#include "emporium.h"

class View {
  public:
    View(Emporium& x) : emp(x) { }
    int select_from_menu();
    int select_flavor();
    int select_container();
    int select_topping();
    int select_toppingamount();
    int select_person();
    int select_amount();
    int select_serving();
    void list_flavor();
    void list_container();
    void list_topping();
    void list_inventory();
    void list_serving();
    void list_person();
    void list_order();
    void list_allorder();
    void list_money();
    void help();
  private:
    string get_flavor();
    string get_container();
    string get_topping();
    string get_toppingamount();
    string get_inventory();
    string get_serving();
    string get_person();
    string get_order();
    string get_allorder();
    string get_money();
    Emporium& emp; 
};
#endif
