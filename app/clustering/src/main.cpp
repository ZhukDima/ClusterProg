#include <iostream>
#include "Analizer.h"

using namespace std;

int main() {
    Analizer analizer;
    analizer.setPathToDirectory("../test_files");
    analizer.setCountDirectory(2);
    analizer.setPathToResult("../output");
    analizer.analize();
    return 0;
}
