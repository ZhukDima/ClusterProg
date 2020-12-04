#include <iostream>
#include <fstream>
#include "FileReader.h"

using namespace std;

int main() {
    FileReader a("../src/FileReader.cpp");
    while (a.hasNextWord()) {
        cout << a.getNextWord() << "\n";
    }
    return 0;
}
