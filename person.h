#ifndef _PERSON_H
#define _PERSON_H

#include <string>

namespace Mice {

class Person {
  public:
    Person(std::string name, int id, std::string phone);
    bool toggle_active();
    virtual std::string type() const;
    std::string name() const;
    std::string phone() const;
    int id() const;
    bool active() const;
  private:
    std::string _name;
    std::string _phone;
    bool _active = true;
    int _id;
    // Gtk::Image _photo;
};

}

std::ostream& operator<<(std::ostream& os, const Mice::Person& person);

#endif
