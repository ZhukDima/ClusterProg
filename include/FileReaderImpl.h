#ifndef FILEREADERIMPL_H
#define FILEREADERIMPL_H

#include <fstream>
#include <string>
#include <functional>

class FileReaderImpl {
public:
    std::string pathToFile;
    std::fstream in;
    FileReaderImpl(std::string _pathToFile);
    ~FileReaderImpl();
    bool hasNextWord();
    std::string readAccepted(std::function<bool(char)> accept);
};

#endif
