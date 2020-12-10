#ifndef FILEMOVER_H
#define FILEMOVER_H

class FileMover {
public:
    FileMover() = default;
    ~FileMover() = default;
    FileMover(const FileMover& obj) = delete;
    FileMover& operator=(const FileMover& obj) = delete;
    void createDir(std::string path);
    void moveFile(std::string pathToSource, std::string pathToDestination);
};

#endif
