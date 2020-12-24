#include "AnalizerImpl.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "1\n";
    Analizer analizer;
    std::cout << "2\n";
    analizer.setCountDirectory(3);
    std::cout << "3\n";
    analizer.setPathToData("../mytest/input");
    std::cout << "4\n";
    analizer.setPathsToCentroids({"../mytest/input/o1.ru.en.txt", "../mytest/input/d0.txt", "../mytest/input/d1.txt"});
    std::cout << "5\n";
    analizer.setPathToResult("../mytest/output/");
    std::cout << "6\n";
    std::cout << " = " << analizer.categorize().size() << std::endl;
    std::cout << "7\n";
    analizer.analize();
    std::cout << "8\n";
}
