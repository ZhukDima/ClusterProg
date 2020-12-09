#include <iostream>
#include "FileReader.h"

using namespace std;

int main() {
    FileReader file("test.txt");
    string str = "";
    while (file.hasNextWord()) {
        str += file.getNextWord() + " ";
    }
    cout << str;
    return 0;
}
