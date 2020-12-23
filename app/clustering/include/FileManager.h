#ifndef FILEMANAGER_H
#define FILEMANAGER_H

class FileManager {
public:
    FileManager() = default;
    ~FileManager() = default;
    FileManager(const FileManager& obj) = delete;
    FileManager& operator=(const FileManager& obj) = delete;
    static void createDir(std::string_view path);
    static void moveFile(std::string_view pathToSource, std::string pathToDestination);
private:
    static const int SAME_FILE_INDEX;
    static std::string getNewFilePathIfExists(std::string_view path, const int idx = FileManager::SAME_FILE_INDEX);
    static std::string constructNewPath(std::string_view path, const int idx);
};

#endif