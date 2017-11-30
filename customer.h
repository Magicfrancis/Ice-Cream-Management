#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include "person.h"

namespace Mice {

class Customer : public Person {
  public:
    Customer(std::string name, int id, std::string phone);
    std::string type() const override;
};

}
#endif
