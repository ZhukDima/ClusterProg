#include "TFIDF.h"
#include <math.h> // log

TFIDF::TFIDF(const std::vector<FileInfo> &filesInfo) : countWordInFiles(filesInfo)
{
    for (const auto &fileInfo : filesInfo)
    {
        pathToIndex[fileInfo.getPath()] = TFMetrics.size();
        TFMetrics.push_back(FileInfo(fileInfo.getPath()));
        for (const auto &[word, count] : fileInfo.getAllMetric())
        {
            TFMetrics.back().setMetric(word, count / fileInfo.getAmountOfWords());
            countFilesWithWord[word] += 1;
        }
    }

    for (const auto &[word, count] : countFilesWithWord)
    {
        IDFMetrics[word] = std::log(filesInfo.size() / count);
    }

    for (const auto &[word, count] : IDFMetrics)
    {
        setUnicWords.insert(word);
    }
}

int TFIDF::countUnicWords() const
{
    return setUnicWords.size();
}

std::set<std::string> TFIDF::getSetUnicWords() const
{
    return setUnicWords;
}

double TFIDF::calculateTFIDFMetric(const std::string &word, const std::string &path) const
{
    try
    {
        return TFMetrics.at(pathToIndex.at(path)).getAllMetric().at(word) * IDFMetrics.at(word);
    }
    catch (const std::out_of_range &e)
    {
        return 0;
    }
}

size_t getNumberFilesWithWord(const std::string &word) const
{
    try
    {
        return countFilesWithWord.at(word);
    }
    catch (const std::out_of_range &e)
    {
        return 0;
    }
}

FileInfo TFIDF::TFIDFForFile(const std::string &path) const
{
    FileInfo fileInfo(path);
    for (auto &[word, count] : TFMetrics.at(pathToIndex.at(path)).getAllMetric())
    {
        fileInfo.setMetric(word, count);
    }
    return fileInfo;
}
