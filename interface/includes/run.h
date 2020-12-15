#ifndef RUN_H
#define RUN_H

#include "mainwindow.h"

#include <QApplication>


class Run
{
public:
    Run() = default;
    ~Run() = default;
    Run(const Run& other) = delete;
    const Run& operator=(const Run& other) = delete;

    static int run(int argc, char* argv[]);

private:
};



#endif // RUN_H
