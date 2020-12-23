#ifndef FILEREADER_H
#define FILEREADER_H

class FileReaderImpl;

class FileReader {
public:
    explicit FileReader(std::string _pathToFile);
    FileReader(const FileReader &obj) = delete;
    FileReader& operator=(const FileReader &obj) = delete;
    bool hasNextWord();
    std::string getNextWord();
    ~FileReader();
private:
    FileReaderImpl* impl = nullptr;
};

#endif
