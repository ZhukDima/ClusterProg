#include "FileInfo.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class TFIDF
{
public:
    bool isContain(string word, const vector<FileInfo> &files);
    int countEntry(string word, const FileInfo &file);
    void computeTF(FileInfo &file);
    void computeIDF(FileInfo &file, const vector<FileInfo> &files);
    void computeTFIDF(vector<FileInfo> &files);
};