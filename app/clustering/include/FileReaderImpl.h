#ifndef FILEREADERIMPL_H
#define FILEREADERIMPL_H

#include <fstream>
#include <string>
#include <functional>

class FileReaderImpl {
public:
    std::string pathToFile;
    std::wfstream in;
    FileReaderImpl(std::string _pathToFile, std::string localization = "ru_RU.UTF8");
    ~FileReaderImpl();
    bool hasNextWord();
    std::wstring readAccepted(const std::function<bool(wchar_t)>& accept);
};

#endif