#ifndef CLUSTERPROG_ANALIZER_HPP
#define CLUSTERPROG_ANALIZER_HPP

#include "DirHandler.h"
#include "KMeans.hpp"
#include "FileManager.h"
#include "Group.h"
#include "TFIDFPP.h"
#include "VectorSpace.hpp"

#include <algorithm>
#include <string>
#include <vector>
#include <set>

class AnalizerImpl;

class Analizer {
public:
    Analizer();

    ~Analizer() = default;

    void setCountDirectory(size_t inputCountDirectory);

    void setPathToResult(const std::string &inputPathToResult);

    void setPathToData(const std::string &inputPathToData);

    void setPathsToCentroids(const std::vector<std::string> &inputPathsToCentroids);

    // распределение файлов по группам
    std::vector<Group> categorize();

    // создание папок и запись файлов
    void move();

    void analize();

private:
    AnalizerImpl *impl = nullptr;
};

#endif //CLUSTERPROG_ANALIZER_HPP