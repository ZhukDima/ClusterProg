#include <string>
#include <vector>
#include <filesystem>
#include <set>
#include "FileInfo.h"
#include "DirHandler.h"

namespace fs = std::filesystem;

std::set <std::string> extensions = {".txt"};

class DirHandlerImpl {
private:
    fs::path pathToDir;
    std::vector <FileInfo> files;
public:
    DirHandlerImpl() = delete;
    DirHandlerImpl(const DirHandlerImpl& obj) = delete;
    DirHandlerImpl& operator=(const DirHandlerImpl& obj) = delete;
    ~DirHandlerImpl() = default;
    DirHandlerImpl(std::string _pathToDir): pathToDir(_pathToDir) {
        if (!fs::exists(pathToDir)) {
            throw "Directory does not exist";
        }
        for (auto &p : fs::directory_iterator(pathToDir)) {
            if (!p.is_directory() && extensions.find(p.path().extension()) != extensions.end()) {
                std::string path = p.path().string();
                FileInfo file;
                try {
                    file = FileInfo(path);
                } catch(const char* err) {
                    continue;
                }
                files.push_back(file);
            }
        }
    }
    DirHandlerImpl(const std::vector<std::string>& pathsToFiles) {
        for (auto &file : pathsToFiles) {
            FileInfo fileInfo;
            try {
                fileInfo = FileInfo(file);
            } catch(const char* err) {
                continue;
            }
            files.push_back(fileInfo);
        }
    }
    std::string getPath() const {
        return pathToDir.string();
    }
    std::vector<FileInfo>& getFiles() {
        return files;
    }
};

DirHandler::DirHandler(std::string _pathToDir): impl(std::make_unique<DirHandlerImpl>(_pathToDir)) {}

DirHandler::DirHandler(const std::vector<std::string> &pathsToFiles): impl(std::make_unique<DirHandlerImpl>(pathsToFiles)) {}

std::string DirHandler::getPath() const {
    return impl->getPath();
}

std::vector<FileInfo>& DirHandler::getFiles() {
    return impl->getFiles();
}

DirHandler::~DirHandler() {
    DirHandlerImpl *p = impl.release();
    delete p;
}
