#include "manager.h"

namespace Mice {

Manager::Manager(std::string name, int id, std::string phone,
              double salary)
          : Person(name, id, phone), _salary{salary} { }
std::string Manager::type() const {return "Manager";}
double Manager::salary() const {return _salary;}
}
