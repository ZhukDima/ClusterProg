#include <iostream>
#include "Analizer.h"

using namespace std;

int main() {
    Analizer analizer("../test_files", {}, "../output", 2);
    analizer.filesMoving();
    return 0;
}
