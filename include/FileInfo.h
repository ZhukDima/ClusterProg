#include <vector>
#include <string>
#include <map>

using std::map;
using std::string;
using std::vector;

class FileInfo
{
private:
    string path;
    map<string, double> metricInfo;

public:
    void setPath(string _path);
    void setMetric(string word, double metric);
    bool isContain(string word, const vector<FileInfo> &files);
    string getPath();
    vector<string> getAllKeys();
    double getMetricByWord(string word);
};