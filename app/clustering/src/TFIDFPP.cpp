#include "TFIDFPP.h"
#include <math.h> // log

TFIDFPP::TFIDFPP(const std::vector<FileInfo> &filesInfo) : TFIDF(filesInfo) {}

std::set<std::string> TFIDFPP::getSetUsefulUnicWords() const
{
    std::set<std::string> setUsefulUnicWords(getSetUnicWords());
    for (auto it = setUsefulUnicWords.begin(); it != setUsefulUnicWords.end();)
    {
        if (getNumberFilesWithWord(*it) == 1)
        {
            it = setUsefulUnicWords.erase(it);
        }
        else
        {
            it++;
        }
    }
    return setUsefulUnicWords;
}
