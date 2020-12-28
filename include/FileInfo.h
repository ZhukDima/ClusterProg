#ifndef FILEINFO_H
#define FILEINFO_H
#include <map>
#include <memory>

class FileInfoImpl;

class FileInfo {
private:
    std::unique_ptr<FileInfoImpl> impl;
public:
    FileInfo();
    FileInfo(std::string _pathToFile, const std::map<std::wstring, double>& _metric);
    explicit FileInfo(std::string _pathToFile);
    FileInfo(const FileInfo& obj);
    FileInfo& operator=(const FileInfo& obj);
    ~FileInfo();

    std::string getPath() const;
    int getAmountOfWords() const;
    const std::map<std::wstring, double>& getAllMetric() const;
    void setMetric(std::wstring key, double value);
    FileInfoImpl getImpl() const;
};

#endif
