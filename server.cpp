#include "server.h"

namespace Mice {

Server::Server(std::string name, int id, std::string phone,
              double salary)
          : Person(name, id, phone), _salary{salary} { }
std::string Server::type() const {return "Server";}
double Server::salary() const {return _salary;}
}
