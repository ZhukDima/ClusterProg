#ifndef DIRHANDLER_H
#define DIRHANDLER_H

#include <vector>
#include "FileInfo.h"

class DirHandlerImpl;

class DirHandler {
private:
    DirHandlerImpl *impl;
public:
    DirHandler() = delete;
    DirHandler(std::string _pathToDir);
    DirHandler(const std::vector<std::string>& pathsToFiles);
    DirHandler(const DirHandler& obj) = delete;
    DirHandler& operator=(const DirHandler& obj) = delete;
    ~DirHandler();

    std::string getPath() const;
    std::vector<FileInfo>& getFiles();
};

#endif
