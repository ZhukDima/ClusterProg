#include <string>
#include <cctype>
#include <functional>
#include "FileReader.h"
#include "FileReaderImpl.h"

bool isLetter(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

bool isSpecialCharacter(char symbol) {
    return symbol == '-' || symbol == '\'';
}


FileReader::FileReader(std::string _pathToFile): impl(new FileReaderImpl(_pathToFile)) {}

bool FileReader::hasNextWord() {
    return impl->hasNextWord();
}

std::string FileReader::getNextWord() {
    if (!hasNextWord()) {
        throw "Unable to read next word";
    }
    impl->readAccepted(std::function<bool(char)>(isLetter));
    std::string word = impl->readAccepted(std::function<bool(char)>([](char symbol){
        return !isLetter(symbol) && !isSpecialCharacter(symbol);
    }));
    return word;
}

// FileReader::~FileReader() {
//     delete impl;
// }
