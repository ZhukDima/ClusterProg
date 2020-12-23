#include "FileReaderImpl.h"

FileReaderImpl::FileReaderImpl(std::string _pathToFile): pathToFile(_pathToFile){
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


std::string FileReaderImpl::readAccepted(std::function<bool(char)> accept) {
    bool exit = false;
    std::string str = "";
    while (hasNextWord() && !exit) {
        char symbol = std::tolower(in.peek());
        if (symbol == EOF || accept(symbol)) {
            exit = true;
        } else {
            str += std::tolower(in.get());
        }
    }
    return str;
}
