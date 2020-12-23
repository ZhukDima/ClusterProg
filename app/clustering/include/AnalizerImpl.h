#ifndef CLUSTERPROG_ANALIZERIMPL_HPP
#define CLUSTERPROG_ANALIZERIMPL_HPP

#include "Analizer.h"

class AnalizerImpl {
private:
    size_t countDirectory;
    std::string pathToResult;
    std::string pathToData;
public:
    AnalizerImpl() = default;

    ~AnalizerImpl() = default;

    void setCountDirectory(size_t inputCountDirectory);

    void setPathToResult(const std::string &inputPathToResult);

    void setPathToData(const std::string &inputPathToData);

    // распределение файлов по группам
    std::vector<Group> categorize();

    // создание папок и запись файлов
    void move();

    // вызов всех методов
    void analize();
};

#endif //CLUSTERPROG_ANALIZERIMPL_HPP
