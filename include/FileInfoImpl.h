#ifndef FILEINFOIMPL_H
#define FILEINFOIMPL_H

class FileInfoImpl {
private:
    std::string pathToFile;
    std::map<std::string, double> metric;
    int amountOfWords = 0;
public:
    FileInfoImpl() = delete;
    FileInfoImpl(std::string _pathToFile);
    FileInfoImpl(std::string _pathToFile, const std::map<std::string, double>& _metric);
    FileInfoImpl(const FileInfoImpl& obj) = delete;
    FileInfoImpl& operator=(const FileInfoImpl& obj) = delete;
    ~FileInfoImpl() = default;

    std::string getPath();
    int getAmountOfWords();
    const std::map<std::string, double>& getAllMetric();
};

#endif
