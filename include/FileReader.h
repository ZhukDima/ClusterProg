class FileReader {
private:
    std::string pathToFile;
    std::fstream in;
    std::string readAccepted(bool(*accept)(char));
public:
    FileReader(std::string _pathToFile);
    FileReader(const FileReader &obj) = delete;
    FileReader& operator=(const FileReader &obj) = delete;
    bool hasNextWord();
    std::string getNextWord();
    ~FileReader();
};
