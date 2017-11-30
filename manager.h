#ifndef _MANAGER_H
#define _MANAGER_H

#include "person.h"

namespace Mice {

class Manager : public Person {
  public:
    Manager(std::string name, int id, std::string phone,
              double salary);
    std::string type() const override;
    double salary() const;
  private:
    double _salary;
};

}
#endif
