#ifndef DIRHANDLER_H
#define DIRHANDLER_H

#include <vector>
#include "FileInfo.h"
#include <memory>

class DirHandlerImpl;

class DirHandler {
private:
    std::unique_ptr <DirHandlerImpl> impl;
public:
    DirHandler() = delete;
    explicit DirHandler(std::string _pathToDir);
    explicit DirHandler(const std::vector<std::string>& pathsToFiles);
    DirHandler(const DirHandler& obj) = delete;
    DirHandler& operator=(const DirHandler& obj) = delete;
    ~DirHandler();

    std::string getPath() const;
    std::vector<FileInfo>& getFiles();
};

#endif