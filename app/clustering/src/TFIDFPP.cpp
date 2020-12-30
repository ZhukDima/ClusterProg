#include "TFIDFPP.h"
#include <math.h> // log

TFIDFPP::TFIDFPP(const std::vector<FileInfo> &filesInfo) : TFIDF(filesInfo) {}

std::set<std::wstring> TFIDFPP::getSetUsefulUnicWords() const
{
    std::set<std::wstring> setUsefulUnicWords(getSetUnicWords());
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
