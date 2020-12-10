#include <AnalizerImpl.h>
#include <algorithm>

void AnalizerImpl::setCountDirectory(size_t inputCountDirectory) {
    countDirectory = inputCountDirectory;
}

void AnalizerImpl::setPathToResult(const std::string &inputPathToResult) {
    pathToResult = inputPathToResult;
}

void AnalizerImpl::setPathToData(const std::string &inputPathToData) {
    pathToData = inputPathToData;
}

std::string cutName(std::string path) {
    std::string answ = "";
    for (int i = path.size() - 1; i >= 0; --i) {
        if (path[i] == '/') {
            break;
        }
        answ += path[i];
    }
    std::reverse(answ.begin(), answ.end());
    return answ;
}

std::vector<Group> AnalizerImpl::categorize() {
    // путь к директории и информация о файлах в директории
    DirHandler directory(pathToData);
    KMeans kmeans(directory.getFiles());
    std::vector<std::set<std::string>> groups = kmeans.calculate(countDirectory);
    std::vector<Group> result;
    size_t count = 0;
    for (auto group : groups) {
        Group tempGroup;
        for (auto filename : group) {
            tempGroup.addFile(cutName(filename));
        }
        result.push_back(tempGroup);
        result[count].setGroupName("group_" + std::to_string(count));
        ++count;
    }
    return result;
}

void AnalizerImpl::move() {
    FileMover mover;
    std::vector<Group> groups = categorize();
    for (const auto &group : groups) {
        mover.createDir(pathToResult + "/" + group.getGroupName());
        for (auto filename : group.getFiles()) {
            mover.moveFile(filename, pathToResult + "/" + group.getGroupName() + "/" + filename);
        }
    }
}

// основная логика по распределению тем(точка входа)
void AnalizerImpl::analize() {
    move();
}
