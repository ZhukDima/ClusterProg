#ifndef CLUSTERPROG_ANALIZERIMPL_H
#define CLUSTERPROG_ANALIZERIMPL_H

#include "Analizer.h"

class AnalizerImpl {
public:
    AnalizerImpl() = delete;

    AnalizerImpl(std::string inputPathToDirectory, std::vector<std::string> inputPathsToFiles,
                 std::string inputPathToResult, size_t inputCountDirectory);

    ~AnalizerImpl() = default;

    [[nodiscard]] std::vector<VectorSpace<double>> getFileInfo(const std::vector<FileInfo> &filesInfo) const;

    [[nodiscard]] std::vector<std::vector<std::string>> getClusteringData(const std::vector<FileInfo> &filesInfo) const;

    // распределение файлов по группам
    std::vector<SimilarFilesGroup> categorize();

    // создание папок перемещение файлов по папкам согласно их группам
    int filesMoving();

private:
    std::string pathToDirectory;
    std::vector<std::string> pathsToFiles;
    std::string pathToResult;
    size_t countDirectory{};
};

#endif //CLUSTERPROG_ANALIZERIMPL_H
