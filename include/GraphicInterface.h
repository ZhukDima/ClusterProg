#include "Analizer.h"
#include <gtkmm.h>

class GraphicInterface{
private:
    Analizer analizer;
    Glib::RefPtr<Gtk::Application> app;
    Gtk::Window window;
public:
    GraphicInterface();
    void buttonChooseDir();
    void buttonAddAdditionalOptions();
    void buttonHelp();
    void infoMessage();
};
