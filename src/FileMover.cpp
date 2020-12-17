#include <string>
#include <cstdlib>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstring>
#include "FileMover.h"

void FileMover::createDir(std::string path) {
    DIR *dir = opendir(path.c_str());
    if (dir != NULL) {
        closedir(dir);
        return;
    }
    const int dir_err = mkdir(path.c_str(), ACCESSPERMS);
    if (dir_err == -1) {
        throw "Unable to create dir " + path;
    }
}

void FileMover::moveFile(std::string pathToSource, std::string pathToDestination) {
    if (std::rename(pathToSource.c_str(), pathToDestination.c_str()) < 0) {
        throw "Unable to move file " + pathToSource;
    }
}
