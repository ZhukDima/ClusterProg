#ifndef CLUSTERPROG_ANALIZERIMPL_HPP
#define CLUSTERPROG_ANALIZERIMPL_HPP

#include "Analizer.h"

class AnalizerImpl {
public:
    AnalizerImpl() = delete;

    AnalizerImpl(std::string inputPathToDirectory, std::vector<std::string> inputPathsToFiles,
                 std::string inputPathToResult, size_t inputCountDirectory);

    ~AnalizerImpl() = default;

    // распределение файлов по группам
    std::vector<SimilarFilesGroup> categorize();

    // создание папок перемещение файлов по папкам согласно их группам
    void filesMoving();

private:
    std::string pathToDirectory;
    std::vector<std::string> pathsToFiles;
    std::string pathToResult;
    size_t countDirectory{};
};

#endif //CLUSTERPROG_ANALIZERIMPL_HPP