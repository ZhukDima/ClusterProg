#ifndef CLUSTERPROG_ANALIZERIMPL_HPP
#define CLUSTERPROG_ANALIZERIMPL_HPP

#include "Analizer.h"

class AnalizerImpl {
private:
    size_t countDirectory{};
    std::string pathToResult;
    std::string pathToDirectory;
    std::vector<std::string> pathsToFiles;
public:
    AnalizerImpl() = default;

    ~AnalizerImpl() = default;

    void setCountDirectory(size_t inputCountDirectory);

    void setPathToResult(const std::string &inputPathToResult);

    void setPathToDirectory(const std::string &inputPathToDirectory);

    void setPathsToFiles(const std::vector<std::string> &inputPathsToFiles);

// распределение файлов по группам
    std::vector<Group> categorize();

// создание папок и запись файлов
    void move();

    void analize();
};

#endif //CLUSTERPROG_ANALIZERIMPL_HPP