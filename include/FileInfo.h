#ifndef FILEINFO_H
#define FILEINFO_H
#include <map>

class FileInfoImpl;

class FileInfo {
private:
    FileInfoImpl *impl = nullptr;
public:
    FileInfo();
    FileInfo(std::string _pathToFile, const std::map<std::string, double>& _metric);
    explicit FileInfo(std::string _pathToFile);
    FileInfo(const FileInfo& obj);
    FileInfo& operator=(const FileInfo& obj);
    ~FileInfo();

    std::string getPath() const;
    int getAmountOfWords() const;
    const std::map<std::string, double>& getAllMetric() const;
    void setMetric(std::string key, double value);
    FileInfoImpl getImpl() const;
};

#endif
