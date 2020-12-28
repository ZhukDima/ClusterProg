#ifndef FILEREADER_H
#define FILEREADER_H
#include <memory>
class FileReaderImpl;

class FileReader {
public:
    explicit FileReader(std::string _pathToFile);
    FileReader(const FileReader &obj) = delete;
    FileReader& operator=(const FileReader &obj) = delete;
    bool hasNextWord();
    std::wstring getNextWord();
    ~FileReader();
private:
    std::unique_ptr<FileReaderImpl> impl;
};

#endif
