#include "customer.h"

namespace Mice {

Customer::Customer(std::string name, int id, std::string phone)
      : Person(name, id, phone) { }
std::string Customer::type() const {return "Customer";}

}
