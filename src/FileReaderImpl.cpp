#include "FileReaderImpl.h"
#include <iostream>
#include <locale>
#include <cctype>

FileReaderImpl::FileReaderImpl(std::string _pathToFile, std::string localization): pathToFile(_pathToFile){
    std::locale loc(localization);
    in.imbue(loc);
    in.open(pathToFile, std::ios_base::in);
    if (!in.is_open()) {
        throw "Unable to read file";
    }
}

FileReaderImpl::~FileReaderImpl() {
    if (in.is_open()) {
        in.close();
    }
}


bool FileReaderImpl::hasNextWord() {
    return in.is_open() && !in.eof();
}


std::wstring FileReaderImpl::readAccepted(const std::function<bool(wchar_t)>& accept) {
    bool exit = false;
    std::wstring str;
    while (hasNextWord() && !exit) {
        wchar_t symbol = (wchar_t)std::tolower((wchar_t)in.peek(), std::locale(""));
        if (symbol == EOF || accept(symbol)) {
            exit = true;
        } else {
            str += (wchar_t)std::tolower((wchar_t)in.get(), std::locale(""));
        }
    }
    return str;
}
