#include <iostream>
#include "Analizer.h"

using namespace std;

int main() {
    Analizer analizer;
    analizer.setPathToData("../test_files");
    analizer.setCountDirectory(3);
    analizer.setPathToResult("../output");
    analizer.analize();
    return 0;
}
