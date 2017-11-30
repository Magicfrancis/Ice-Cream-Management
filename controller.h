#ifndef __CONTROLLER_H
#define __CONTROLLER_H 
 
#include "emporium.h"
#include "view.h"

class Controller {
  public:
    Controller (Emporium& x) : emp(x), view(View(emp)) { }
    void cli();
    void execute_cmd(int cmd);
  private:
    Emporium& emp; 
    View view;
};
#endif
