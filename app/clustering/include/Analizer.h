#ifndef CLUSTERPROG_ANALIZER_HPP
#define CLUSTERPROG_ANALIZER_HPP

#include "DirHandler.h"
#include "KMeans.hpp"
#include "FileManager.h"
#include "SimilarFilesGroup.h"
#include "TFIDFPP.h"
#include "VectorSpace.hpp"

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <filesystem>

class AnalizerImpl;

class Analizer {
public:
    Analizer() = delete;

    Analizer(std::string inputPathToDirectory, std::vector<std::string> inputPathsToFiles,
             std::string inputPathToResult, size_t inputCountDirectory);

    ~Analizer() = default;

    // распределение файлов по группам
    std::vector<SimilarFilesGroup> categorize();

    // создание папок перемещение файлов по папкам согласно их группам
    void filesMoving();

private:
    AnalizerImpl *impl = nullptr;
};

#endif //CLUSTERPROG_ANALIZER_HPP