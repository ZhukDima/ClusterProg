#include <string>
#include <vector>
#include <dirent.h>
#include "FileInfo.h"
#include "DirHandler.h"

class DirHandlerImpl {
private:
    std::string pathToDir;
    std::vector <FileInfo> files;
public:
    DirHandlerImpl() = delete;
    DirHandlerImpl(const DirHandlerImpl& obj) = delete;
    DirHandlerImpl& operator=(const DirHandlerImpl& obj) = delete;
    ~DirHandlerImpl() = default;
    DirHandlerImpl(std::string _pathToDir): pathToDir(_pathToDir) {
        DIR *dir = opendir(pathToDir.c_str());
        if (dir == NULL) {
            throw "Unable to open directory";
        }
        struct dirent *el;
        while ((el = readdir(dir)) != NULL) {
            if (el->d_type == 4) {
                continue;
            }
            std::string pathToFile = pathToDir;
            if (pathToFile[pathToFile.size() - 1] == '/') {
                pathToFile += el->d_name;
            } else {
                pathToFile += "/";
                pathToFile += el->d_name;
            }
            FileInfo file;
            try {
                file = FileInfo(pathToFile);
            } catch(const char* err) {
                continue;
            }
            files.push_back(file);
        }
        if (closedir(dir) == -1) {
            throw "Unable to close directory";
        }
    }
    std::string getPath() const {
        return pathToDir;
    }
    std::vector<FileInfo>& getFiles() {
        return files;
    }
};

DirHandler::DirHandler(std::string _pathToDir): impl(new DirHandlerImpl(_pathToDir)) {}

std::string DirHandler::getPath() const {
    return impl->getPath();
}

std::vector<FileInfo>& DirHandler::getFiles() {
    return impl->getFiles();
}

DirHandler::~DirHandler() {
    delete impl;
}
