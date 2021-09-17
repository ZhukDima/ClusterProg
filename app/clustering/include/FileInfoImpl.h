#ifndef FILEINFOIMPL_H
#define FILEINFOIMPL_H

class FileInfoImpl {
private:
    std::string pathToFile;
    std::map<std::wstring, double> metric;
    int amountOfWords = 0;
    void swap(const FileInfoImpl& obj) noexcept;
public:
    FileInfoImpl();
    explicit FileInfoImpl(std::string _pathToFile);
    FileInfoImpl(std::string _pathToFile, const std::map<std::wstring, double>& _metric);
    FileInfoImpl(const FileInfoImpl& obj);
    FileInfoImpl& operator=(const FileInfoImpl& obj);
    ~FileInfoImpl() = default;

    std::string getPath() const;
    int getAmountOfWords() const;
    const std::map<std::wstring, double>& getAllMetric() const;
    void setMetric(std::wstring key, double value);
};

#endif