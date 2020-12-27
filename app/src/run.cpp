#include "run.h"
#include <QApplication>

int Run::run(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
