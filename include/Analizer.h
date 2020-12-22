#ifndef CLUSTERPROG_ANALIZER_HPP
#define CLUSTERPROG_ANALIZER_HPP

#include "DirHandler.h"
#include "KMeans.h"
#include "FileManager.h"
#include "Group.h"

#include <string>
#include <vector>

class AnalizerImpl;

class Analizer {
public:
    Analizer();

    ~Analizer() = default;

    void setCountDirectory(size_t inputCountDirectory);

    void setPathToResult(const std::string &inputPathToResult);

    void setPathToData(const std::string &inputPathToData);

    // распределение файлов по группам
    std::vector<Group> categorize();

    // создание папок и запись файлов
    void move();

    // вызов всех методов
    void analize();

private:
    AnalizerImpl *impl = nullptr;
};

#endif //CLUSTERPROG_ANALIZER_HPP
