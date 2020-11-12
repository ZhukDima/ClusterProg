#ifndef CLUSTERPROG_ANALIZER_HPP
#define CLUSTERPROG_ANALIZER_HPP

#include "DirHandler.h"
#include "Group.h"

#include <string>
#include <vector>

class Analizer {
private:
    DirHandler directory;
    std::string pathToResult;
    std::string pathToData;
    std::vector<Group> groups;
public:
    Analizer();

    ~Analizer();

    void setPathToResult(std::string inputPathToResult);

    void setPathToData(std::string inputPathToData);

    std::vector<std::string> getMainThemes(int count);

    std::vector<Group> categorize();

    void move();

    void analize();
};

#endif //CLUSTERPROG_ANALIZER_HPP
