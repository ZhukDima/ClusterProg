//
// Created by alexis on 11/30/20.
//

#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "FileReader.h"

FileReader::FileReader(std::string _pathToFile): pathToFile(_pathToFile) {
    in.open(pathToFile, std::ios_base::in);
    if (!in.is_open()) {
        throw "Unable to read file";
    }
}

bool FileReader::hasNextWord() {
    return in.is_open() && !in.eof();
}

bool isLetter(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

bool isSpecialCharacter(char symbol) {
    return symbol == '-' || symbol == '\'';
}

std::string FileReader::readAccepted(bool(*accept)(char)) {
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

std::string FileReader::getNextWord() {
    if (!hasNextWord()) {
        throw "Unable to read next word";
    }
    readAccepted(isLetter);
    std::string word = readAccepted([](char symbol){
        return !isLetter(symbol) && !isSpecialCharacter(symbol);
    });
    return word;
}

FileReader::~FileReader() {
    if (in.is_open()) {
        in.close();
    }
}
