#ifndef TFIDFPP_H
#define TFIDFPP_H

#include "TFIDF.h"

class TFIDFPP : public TFIDF
{
public:
    TFIDFPP(const std::vector<FileInfo> &filesInfo);

    std::set<std::wstring> getSetUsefulUnicWords() const;
};

#endif
