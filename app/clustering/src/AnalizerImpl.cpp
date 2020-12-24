#include <AnalizerImpl.h>

void AnalizerImpl::setCountDirectory(size_t inputCountDirectory) {
    countDirectory = inputCountDirectory;
}

void AnalizerImpl::setPathToResult(const std::string &inputPathToResult) {
    pathToResult = inputPathToResult;
}

void AnalizerImpl::setPathToDirectory(const std::string &inputPathToDirectory) {
    pathToDirectory = inputPathToDirectory;
}

std::string cutName(std::string path) {
    std::string answ;
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
    DirHandler *directory = nullptr;
    if (pathsToFiles.empty()) {
        directory = new DirHandler(pathToDirectory);
    } else {
        directory = new DirHandler(pathsToFiles);
    }
    std::vector<FileInfo> filesInfo = directory->getFiles();
    TFIDFPP tfidf(filesInfo);
    std::set<std::string> setUnicWords = tfidf.getSetUsefulUnicWords();
    std::vector<VectorSpace<double>> vectorsSpace;
    for (auto &fileInfo : filesInfo) {
        vectorsSpace.emplace_back(setUnicWords.size());
        size_t i = 0;
        for (auto &word : setUnicWords) {
            vectorsSpace.back()[i++] = tfidf.calculateTFIDFMetric(word, fileInfo.getPath());
        }
    }
    KMeans<VectorSpace<double>> kMeans(vectorsSpace);

    std::vector<VectorSpace<double>> vectorsCentroids;
/*    for (const auto &pathToFile : pathsToFiles) {
        for (const auto &fileInfo : filesInfo) {
            if (pathToFile == fileInfo.getPath()) {
                vectorsCentroids.emplace_back(setUnicWords.size());
                size_t i = 0;
                for (auto &word : setUnicWords) {
                    vectorsCentroids.back()[i++] = tfidf.calculate(word, fileInfo.getPath());
                }
                break;
            }
        }
    }*/
    std::vector<Cluster> clusters = kMeans.calculate(countDirectory, vectorsCentroids);

    std::vector<std::string> allPath;
    for (auto &fileInfo : filesInfo) {
        allPath.push_back(fileInfo.getPath());
    }
    std::vector<std::vector<std::string>> clusteringData;
    for (auto &cluster : clusters) {
        clusteringData.push_back(cluster.getClusteringDataByData(allPath));
    }
    std::vector<Group> result;
    size_t count = 0;
    for (const auto &group : clusteringData) {
        if (group.empty()) {
            continue;
        }
        Group tempGroup;
        for (const auto &filename : group) {
            tempGroup.addFile(filename);
        }
        result.push_back(tempGroup);
        result[count].setGroupName("group_" + std::to_string(count));
        ++count;
    }
    delete directory;
    return result;
}

void AnalizerImpl::move() {
    FileManager mover;
    std::vector<Group> groups = categorize();
    for (const auto &group : groups) {
        mover.createDir(pathToResult + "/" + group.getGroupName());
        for (auto filename : group.getFiles()) {
            mover.moveFile(filename, pathToResult + "/" + group.getGroupName() + "/" + cutName(filename));
        }
    }
}

void AnalizerImpl::analize() {
    move();
}

void AnalizerImpl::setPathsToFiles(const std::vector<std::string> &inputPathsToFiles) {
    pathsToFiles = inputPathsToFiles;
}