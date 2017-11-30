#ifndef _SERVER_H
#define _SERVER_H

#include "person.h"

namespace Mice {

class Server : public Person {
  public:
    Server(std::string name, int id, std::string phone,
              double salary);
    std::string type() const override;
    double salary() const;
  private:
    double _salary;
};

}
#endif
