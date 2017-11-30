#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "controller.h"

class Main_window : public Gtk::Window
{
    public:
        Main_window();
        virtual ~Main_window();
    protected:
        void on_addflavor_click();
        void on_addcontainer_click();
        void on_addtopping_click();
        void on_addserving_click();
        void on_addcustomer_click();
        void on_addserver_click();
        void on_addmanager_click();
        void on_addorder_click();
        void on_quit_click();
        void on_listmoney_click();
        void on_listinventory_click();
        void on_listserving_click();
        void on_listorder_click();
        void on_easter_click();
        void on_about_click();
        void on_savefile_click();
        void on_loadfile_click();
        void on_all_click();                           // Select all roles
        void on_owner_click();                         // Select owner role
        void on_manager_click();                       // Select manager role
        void on_server_click();                        // Select server role
        void on_customer_click();                      // Select customer role
    private:
        Gtk::MenuItem *menuitem_savefile;
        Gtk::MenuItem *menuitem_loadfile;
        Gtk::MenuItem *menuitem_money;
        Gtk::MenuItem *menuitem_addserver;
        Gtk::MenuItem *menuitem_addmanager;
        Gtk::MenuItem *menuitem_invlist;
        Gtk::MenuItem *menuitem_addflavor;
        Gtk::MenuItem *menuitem_addcontainer;
        Gtk::MenuItem *menuitem_addtopping;
        Gtk::MenuItem *menuitem_easter;  
        Gtk::MenuItem *menuitem_quit;

	Gtk::Image *addflavor_image;
	Gtk::ToolButton *addflavor;
	Gtk::Image *addcontainer_image;
	Gtk::ToolButton *addcontainer;
	Gtk::Image *addtopping_image;
	Gtk::ToolButton *addtopping;
	Gtk::Image *addserving_image;
	Gtk::ToolButton *addserving;
	Gtk::Image *listserving_image;
	Gtk::ToolButton *listserving;
	Gtk::Image *listinventory_image;
	Gtk::ToolButton *listinventory;
	Gtk::Image *help_image;
	Gtk::ToolButton *help;
	Gtk::Image *quit_image;
	Gtk::ToolButton *quit;
};
#endif 

