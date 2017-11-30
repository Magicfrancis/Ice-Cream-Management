#include "person.h"
#include <iostream>
#include <iomanip>

namespace Mice {

Person::Person(std::string name, int id, std::string phone)
     : _name{name}, _id{id}, _phone{phone} { }
std::string Person::type() const {return "Person";}
bool Person::toggle_active() {_active = false;}
std::string Person::name() const {return _name;}
std::string Person::phone() const {return _phone;}
int Person::id() const {return _id;}
bool Person::active() const {return _active;}

// Gtk::Image photo() {return _photo;}
}

/*
std::ostream& operator<<(std::ostream& os, const Mice::Item& item) {
    os << item.name() << " (" << item.description() << ") cost: $" 
       << std::setprecision(2) << std::fixed << item.cost() << ", price: $" << item.price() 
       << ", quantity: " << item.quantity();
    return os;
}
*/

// OPERATOR OVERLOADING FRANCISLE
std::ostream& operator<<(std::ostream& os, const Mice::Person& person) {
    os << std::setw(40) << person.type() + ": " + person.name() << " id: " 
       << std::setprecision(5) << std::fixed << person.id(); 
    return os;
}

