#ifndef FILEMOVER_H
#define FILEMOVER_H

class FileMover {
public:
    FileMover() = default;
    ~FileMover() = default;
    FileMover(const FileMover& obj) = delete;
    FileMover& operator=(const FileMover& obj) = delete;
    static void createDir(const std::string& path);
    static void moveFile(const std::string& pathToSource, std::string pathToDestination);
private:
    static const int SAME_FILE_INDEX;
    static std::string getNewFilePathIfExists(std::string path, int idx = FileMover::SAME_FILE_INDEX);
    static std::string constructNewPath(std::string path, int idx);
};

#endif