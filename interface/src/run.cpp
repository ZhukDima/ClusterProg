#include "run.h"
#include <QApplication>

int Run::run(int argc, char* argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("../icon.svg"));
    MainWindow w;
    w.show();
    return a.exec();
}
