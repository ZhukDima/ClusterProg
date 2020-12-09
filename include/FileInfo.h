#ifndef FILEINFO_H
#define FILEINFO_H
#include <map>

class FileInfoImpl;

class FileInfo {
private:
    FileInfoImpl *impl = nullptr;
public:
    FileInfo() = delete;
    FileInfo(std::string _pathToFile, const std::map<std::string, double>& _metric);
    FileInfo(std::string _pathToFile);
    FileInfo(const FileInfo& obj) = delete;
    FileInfo& operator=(const FileInfo& obj) = delete;
    ~FileInfo();

    std::string getPath();
    int getAmountOfWords();
    const std::map<std::string, double>& getAllMetric();
};

#endif
