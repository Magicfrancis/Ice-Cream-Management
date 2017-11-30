#include "main_window.h"

Emporium emp;
Controller controller(emp);

Main_window::Main_window() { 

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(700, 200);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         Save File
    // Append Save to the File menu
    menuitem_savefile = Gtk::manage(new Gtk::MenuItem("_Save File", true));
    menuitem_savefile->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_savefile_click));
    filemenu->append(*menuitem_savefile);

    //         Load File
    // Append Load to the File menu
    menuitem_loadfile = Gtk::manage(new Gtk::MenuItem("_Load File", true));
    menuitem_loadfile->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_loadfile_click));
    filemenu->append(*menuitem_loadfile);

    //         Q U I T
    // Append Quit to the File menu
    menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);

    //     R O L E
    // Create a Role menu and add to the menu bar
    Gtk::MenuItem *menuitem_role = Gtk::manage(new Gtk::MenuItem("Role", true));
    menubar->append(*menuitem_role);
    Gtk::Menu *rolemenu = Gtk::manage(new Gtk::Menu());
    menuitem_role->set_submenu(*rolemenu);

    //           A L L
    // Append All to the Role menu
    Gtk::MenuItem *menuitem_all_role = Gtk::manage(new Gtk::MenuItem("All", true));
    menuitem_all_role->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_all_click));
    rolemenu->append(*menuitem_all_role);

    //           O W N E R
    // Append Owner to the Role menu
    Gtk::MenuItem *menuitem_owner_role = Gtk::manage(new Gtk::MenuItem("Owner", true));
    menuitem_owner_role->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_owner_click));
    rolemenu->append(*menuitem_owner_role);

    //           M A N A G E R
    // Append Manager to the Role menu
    Gtk::MenuItem *menuitem_manager_role = Gtk::manage(new Gtk::MenuItem("Manager", true));
    menuitem_manager_role->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_manager_click));
    rolemenu->append(*menuitem_manager_role);

    //           S E R V E R
    // Append Manager to the Role menu
    Gtk::MenuItem *menuitem_server_role = Gtk::manage(new Gtk::MenuItem("Server", true));
    menuitem_server_role->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_server_click));
    rolemenu->append(*menuitem_server_role);

    //           C U S T O M E R
    // Append Customer to the Role menu
    Gtk::MenuItem *menuitem_customer_role = Gtk::manage(new Gtk::MenuItem("Customer", true));
    menuitem_customer_role->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_customer_click));
    rolemenu->append(*menuitem_customer_role);


    //     People
    // Create a People menu and add to the menu bar
    Gtk::MenuItem *menuitem_pepe = Gtk::manage(new Gtk::MenuItem("_People", true));
    menubar->append(*menuitem_pepe);
    Gtk::Menu *pepemenu = Gtk::manage(new Gtk::Menu());
    menuitem_pepe->set_submenu(*pepemenu);

    //        People ADD CUSTOMER
    // Append Add CUSTOMER to the PEOPLE menu
    Gtk::MenuItem *menuitem_addcust = Gtk::manage(new Gtk::MenuItem("_Add Customer", true));
    menuitem_addcust->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addcustomer_click));
    pepemenu->append(*menuitem_addcust);

    //        People ADD SERVER
    // Append Add SERVER to the PEOPLE menu
    menuitem_addserver = Gtk::manage(new Gtk::MenuItem("_Add Server", true));
    menuitem_addserver->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addserver_click));
    pepemenu->append(*menuitem_addserver);

    //     Inventory
    // Create a Inventory menu and add to the menu bar
    Gtk::MenuItem *menuitem_invent = Gtk::manage(new Gtk::MenuItem("_Management", true));
    menubar->append(*menuitem_invent);
    Gtk::Menu *inventmenu = Gtk::manage(new Gtk::Menu());
    menuitem_invent->set_submenu(*inventmenu);

    //        Inventory MONEY
    // Append List to the Inventory menu
    menuitem_money = Gtk::manage(new Gtk::MenuItem("_Money Statistic", true));
    menuitem_money->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_listmoney_click));
    inventmenu->append(*menuitem_money);

    //        Inventory LIST
    // Append List to the Inventory m
    menuitem_invlist = Gtk::manage(new Gtk::MenuItem("_List Inventory", true));
    menuitem_invlist->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_listinventory_click));
    inventmenu->append(*menuitem_invlist);

    //        Inventory ADD FLAVOR
    // Append Add FLAVOR to the INVENTORY menu
    menuitem_addflavor = Gtk::manage(new Gtk::MenuItem("_Add Flavor", true));
    menuitem_addflavor->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addflavor_click));
    inventmenu->append(*menuitem_addflavor);

    //        Inventory ADD CONTAINER
    // Append Add CONTAINER to the INVENTORY menu
    menuitem_addcontainer = Gtk::manage(new Gtk::MenuItem("_Add Container", true));
    menuitem_addcontainer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addcontainer_click));
    inventmenu->append(*menuitem_addcontainer);

    //        Inventory ADD TOPPING
    // Append Add TOPPING to the INVENTORY menu
    menuitem_addtopping = Gtk::manage(new Gtk::MenuItem("_Add Topping", true));
    menuitem_addtopping->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addtopping_click));
    inventmenu->append(*menuitem_addtopping);

    //     SERVING
    // Create a Serving menu and add to the menu bar
    Gtk::MenuItem *menuitem_serving = Gtk::manage(new Gtk::MenuItem("_Serving", true));
    menubar->append(*menuitem_serving);
    Gtk::Menu *servingmenu = Gtk::manage(new Gtk::Menu());
    menuitem_serving->set_submenu(*servingmenu);

    //        SERVING LIST
    // Append List to the Serving menu
    Gtk::MenuItem *menuitem_servinglist = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_servinglist->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_listserving_click));
    servingmenu->append(*menuitem_servinglist);

    //        SERVING ADD SERVING
    // Append ADD SERVING to the Serving menu
    Gtk::MenuItem *menuitem_addserving = Gtk::manage(new Gtk::MenuItem("_Add Serving", true));
    menuitem_addserving->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addserving_click));
    servingmenu->append(*menuitem_addserving);

    //     ORDER
    // Create a ORDER menu and add to the menu bar
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menubar->append(*menuitem_order);
    Gtk::Menu *ordermenu = Gtk::manage(new Gtk::Menu());
    menuitem_order->set_submenu(*ordermenu);

    //        ORDER LIST ORDER
    // Append LIST ORDER to the ORDER menu
    Gtk::MenuItem *menuitem_listorder = Gtk::manage(new Gtk::MenuItem("_List All Order", true));
    menuitem_listorder->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_listorder_click));
    ordermenu->append(*menuitem_listorder);

    //        ORDER ADD ORDER
    // Append Add ORDER to the ORDER menu
    Gtk::MenuItem *menuitem_addorder = Gtk::manage(new Gtk::MenuItem("_Add Order", true));
    menuitem_addorder->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addorder_click));
    ordermenu->append(*menuitem_addorder);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           EASTER
    // Append easter to the Help menu
    menuitem_easter = Gtk::manage(new Gtk::MenuItem("Easter", true));
    menuitem_easter->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_easter_click));
    helpmenu->append(*menuitem_easter);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    helpmenu->append(*menuitem_about);


    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

         //Add Inventory toolbar
    // Add a icon for add flavor
    addflavor_image = Gtk::manage(new Gtk::Image("button_addflavor.png"));
    addflavor = Gtk::manage(new Gtk::ToolButton(*addflavor_image));
    addflavor->set_tooltip_markup("Click to add Flavor");
    addflavor->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addflavor_click));
    toolbar->append(*addflavor);

    // Add a icon for add container
    addcontainer_image = Gtk::manage(new Gtk::Image("button_addcontainer.png"));
    addcontainer = Gtk::manage(new Gtk::ToolButton(*addcontainer_image));
    addcontainer->set_tooltip_markup("Click to add Container");
    addcontainer->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addcontainer_click));
    toolbar->append(*addcontainer);

    // Add a icon for add topping
    addtopping_image = Gtk::manage(new Gtk::Image("button_addtopping.png"));
    addtopping = Gtk::manage(new Gtk::ToolButton(*addtopping_image));
    addtopping->set_tooltip_markup("Click to add Topping");
    addtopping->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addtopping_click));
    toolbar->append(*addtopping);

    // Add a icon for list inventory
    listinventory_image = Gtk::manage(new Gtk::Image("button_listinventory.png"));
    listinventory = Gtk::manage(new Gtk::ToolButton(*listinventory_image));
    listinventory->set_tooltip_markup("Click to list Inventory");
    listinventory->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_listinventory_click));
    toolbar->append(*listinventory);


         //Serving  toolbar
    // Add a icon for add serving
    addserving_image = Gtk::manage(new Gtk::Image("button_addserving.png"));
    addserving = Gtk::manage(new Gtk::ToolButton(*addserving_image));
    addserving->set_tooltip_markup("Click to add Serving");
    addserving->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addserving_click));
    Gtk::SeparatorToolItem *sep2 = Gtk::manage(new Gtk::SeparatorToolItem());
    sep2->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep2);
    toolbar->append(*addserving);

    // Add a icon for list serving
    listserving_image = Gtk::manage(new Gtk::Image("button_listserving.png"));
    listserving = Gtk::manage(new Gtk::ToolButton(*listserving_image));
    listserving->set_tooltip_markup("Click to list Serving");
    listserving->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_listserving_click));
    toolbar->append(*listserving);


         //Help toolbar
    // Add a icon for Help
    help_image = Gtk::manage(new Gtk::Image("button_help.png"));
    help = Gtk::manage(new Gtk::ToolButton(*help_image));
    help->set_tooltip_markup("Click for Help");
    help->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    sep1->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep1);
    toolbar->append(*help);

         //Quit toolbar
    // Add a icon for quit
    quit_image = Gtk::manage(new Gtk::Image("button_quit.png"));
    quit = Gtk::manage(new Gtk::ToolButton(*quit_image));
    quit->set_tooltip_markup("Exit System");
    quit->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit);


    // Make the box and everything in it visible
    vbox->show_all();

}

Main_window::~Main_window() { }
void Main_window::on_addflavor_click() {
    controller.execute_cmd(1);
}
void Main_window::on_addcontainer_click() {
    controller.execute_cmd(2);
}
void Main_window::on_addtopping_click() {
    controller.execute_cmd(3);
}
void Main_window::on_addcustomer_click() {
  controller.execute_cmd(11);    
}
void Main_window::on_addserver_click() {
  controller.execute_cmd(12);    
}
void Main_window::on_addorder_click() {
  controller.execute_cmd(13);  
}
void Main_window::on_listmoney_click() {
    controller.execute_cmd(14);
}
void Main_window::on_savefile_click() {
    controller.execute_cmd(15);
}
void Main_window::on_loadfile_click() {
    controller.execute_cmd(16);
}
void Main_window::on_listorder_click() {
    controller.execute_cmd(17);
}
void Main_window::on_listinventory_click() {
    controller.execute_cmd(4);
}
void Main_window::on_addserving_click() {
    controller.execute_cmd(5);
}
void Main_window::on_listserving_click() {
    controller.execute_cmd(6);
}
void Main_window::on_quit_click() {
    hide();
}
void Main_window::on_about_click() {
    controller.execute_cmd(9);
}
void Main_window::on_easter_click() {
    controller.execute_cmd(99);
}
void Main_window::on_all_click() {
    menuitem_savefile->set_sensitive(true);
    menuitem_loadfile->set_sensitive(true);
    menuitem_money->set_sensitive(true);
    menuitem_addserver->set_sensitive(true);
    menuitem_invlist->set_sensitive(true);
    menuitem_addflavor->set_sensitive(true);
    menuitem_addcontainer->set_sensitive(true);
    menuitem_addtopping->set_sensitive(true);
    menuitem_easter->set_sensitive(true);
    menuitem_quit->set_sensitive(true);

    addflavor->set_sensitive(menuitem_addflavor->get_sensitive());
    addcontainer->set_sensitive(menuitem_addcontainer->get_sensitive());
    addtopping->set_sensitive(menuitem_addtopping->get_sensitive());
    quit->set_sensitive(menuitem_quit->get_sensitive());

}
void Main_window::on_owner_click() {
    menuitem_savefile->set_sensitive(true);
    menuitem_loadfile->set_sensitive(true);
    menuitem_money->set_sensitive(true);
    menuitem_addserver->set_sensitive(true);
    menuitem_invlist->set_sensitive(true);
    menuitem_addflavor->set_sensitive(true);
    menuitem_addcontainer->set_sensitive(true);
    menuitem_addtopping->set_sensitive(true);
    menuitem_easter->set_sensitive(true);
    menuitem_quit->set_sensitive(true);

    addflavor->set_sensitive(menuitem_addflavor->get_sensitive());
    addcontainer->set_sensitive(menuitem_addcontainer->get_sensitive());
    addtopping->set_sensitive(menuitem_addtopping->get_sensitive());
    quit->set_sensitive(menuitem_quit->get_sensitive());
}
void Main_window::on_manager_click() {
    menuitem_savefile->set_sensitive(true);
    menuitem_loadfile->set_sensitive(true);
    menuitem_money->set_sensitive(true);
    menuitem_addserver->set_sensitive(true);
    menuitem_invlist->set_sensitive(true);
    menuitem_addflavor->set_sensitive(true);
    menuitem_addcontainer->set_sensitive(true);
    menuitem_addtopping->set_sensitive(true);
    menuitem_easter->set_sensitive(true);
    menuitem_quit->set_sensitive(true);

    addflavor->set_sensitive(menuitem_addflavor->get_sensitive());
    addcontainer->set_sensitive(menuitem_addcontainer->get_sensitive());
    addtopping->set_sensitive(menuitem_addtopping->get_sensitive());
    quit->set_sensitive(menuitem_quit->get_sensitive());
}
void Main_window::on_server_click() {
    menuitem_savefile->set_sensitive(false);
    menuitem_loadfile->set_sensitive(false);
    menuitem_money->set_sensitive(false);
    menuitem_addserver->set_sensitive(false);
    menuitem_invlist->set_sensitive(true);
    menuitem_addflavor->set_sensitive(false);
    menuitem_addcontainer->set_sensitive(false);
    menuitem_addtopping->set_sensitive(false);
    menuitem_easter->set_sensitive(false);
    menuitem_quit->set_sensitive(false);

    addflavor->set_sensitive(menuitem_addflavor->get_sensitive());
    addcontainer->set_sensitive(menuitem_addcontainer->get_sensitive());
    addtopping->set_sensitive(menuitem_addtopping->get_sensitive());
    quit->set_sensitive(menuitem_quit->get_sensitive());
}
void Main_window::on_customer_click() {
    menuitem_savefile->set_sensitive(false);
    menuitem_loadfile->set_sensitive(false);
    menuitem_money->set_sensitive(false);
    menuitem_addserver->set_sensitive(false);
    menuitem_invlist->set_sensitive(false);
    menuitem_addflavor->set_sensitive(false);
    menuitem_addcontainer->set_sensitive(false);
    menuitem_addtopping->set_sensitive(false);
    menuitem_easter->set_sensitive(false);
    menuitem_quit->set_sensitive(false);

    listinventory->set_sensitive(menuitem_invlist->get_sensitive());
    addflavor->set_sensitive(menuitem_addflavor->get_sensitive());
    addcontainer->set_sensitive(menuitem_addcontainer->get_sensitive());
    addtopping->set_sensitive(menuitem_addtopping->get_sensitive());
    quit->set_sensitive(menuitem_quit->get_sensitive());
}


