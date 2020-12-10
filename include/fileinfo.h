#include "map"

class FileInfo
{
private:
public:
    FileInfo(std::string path, const std::map<std::string, double> &_metric);
    const std::map<std::string, double> &getAllMetric() const;
    std::string getPath() const;
    int getAmountOfWords() const;
};