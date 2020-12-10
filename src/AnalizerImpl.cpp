#include <AnalizerImpl.h>

void AnalizerImpl::setCountDirectory(size_t inputCountDirectory) {
    countDirectory = inputCountDirectory;
}

void AnalizerImpl::setPathToResult(const std::string &inputPathToResult) {
    pathToResult = inputPathToResult;
}

void AnalizerImpl::setPathToData(const std::string &inputPathToData) {
    pathToData = inputPathToData;
}

std::vector<Group> AnalizerImpl::categorize() {
    // путь к директории и информация о файлах в директории
    DirHandler directory(pathToData);
    Kmeans kmeans(directory.getFiles());
    std::vector<std::set<std::string>> groups = kmeans.calculate();
    std::vector<Group> result;
    size_t count = 0;
    for (auto group : groups) {
        Group tempGroup;
        for (const auto &filename : group.getFiles()) {
            tempGroup.addFile(filename);
        }
        result.push_back(tempGroup);
        group.setGroupName("group_" + std::to_string(count));
        ++count;
    }
    return result;
}

void AnalizerImpl::move() {
    createDir(pathToResult);
    std::vector<Group> groups = categorize();
    for (const auto &group : groups) {
        createDir(pathToResult + "/" + group.getGroupName());
        for (const auto &filename : group.getFiles()) {
            moveFile(filename, pathToResult + "/" + group.getGroupName() + "/" + filename);
        }
    }
}

// основная логика по распределению тем(точка входа)
void AnalizerImpl::analize() {
    move();
}
