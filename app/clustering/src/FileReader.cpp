#include <string>
#include <cctype>
#include <functional>
#include "FileReader.h"
#include "FileReaderImpl.h"
#include <cctype>
#include <iostream>

bool isLetter(wchar_t symbol) {
    return std::isalpha(symbol, std::locale(""));
}

bool isSpecialCharacter(wchar_t symbol) {
    return symbol == L'-' || symbol == L'\'';
}


FileReader::FileReader(std::string _pathToFile): impl(new FileReaderImpl(_pathToFile)) {}

bool FileReader::hasNextWord() {
    return impl->hasNextWord();
}

std::wstring FileReader::getNextWord() {
    if (!hasNextWord()) {
        throw "Unable to read next word";
    }
    impl->readAccepted(std::function<bool(wchar_t)>(isLetter));
    std::wstring word = impl->readAccepted(std::function<bool(wchar_t)>([](wchar_t symbol){
        return !isLetter(symbol) && !isSpecialCharacter(symbol);
    }));
    return word;
}

FileReader::~FileReader() {
    delete impl;
}