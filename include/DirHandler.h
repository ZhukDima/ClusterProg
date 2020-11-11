#include "FileInfo.h"
#include <vector>

class DirHandler{
private:
    std::vector <FileInfo> files;
    std::string path;
public:
    DirHandler();
    DirHandler(std::string _path, const std::vector <FileInfo> &_files);
    ~DirHandler();
    void setPath();
    void readDir();
    void computeMetric();
    std::vector <FileInfo> getFilesInfo();
};
