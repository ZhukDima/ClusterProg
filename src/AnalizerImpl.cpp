#include <AnalizerImpl.h>
#include "UniversalCalcDelta.hpp"
#include "UniversalCompEqual.hpp"
#include "UniversalMakeCentroid.hpp"

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
    DirHandler directory(pathToData);
    std::vector<FileInfo> filesInfo = directory.getFiles();
    TFIDF tfidf(filesInfo);
    std::set<std::string> setUnicWords = tfidf.getSetUnicWords();
    std::vector<VectorSpace<double>> vectorsSpace;
    for (auto &fileInfo : filesInfo) {
        //vectorsSpace.push_back(VectorSpace<double>(setUnicWords.size()));
        vectorsSpace.emplace_back(setUnicWords.size());
        size_t i = 0;
        for (auto &word : setUnicWords) {
            vectorsSpace.back()[i++] = tfidf.calculate(word, fileInfo.getPath());
        }
    }
    KMeans<VectorSpace<double>> kMeans(vectorsSpace);
    std::vector<Cluster> clusters = kMeans.calculate<UniversalCalcDelta, UniversalCompEqual, UniversalMakeCentroid>(countDirectory);

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
    for (auto group : clusteringData) {
        if (group.empty()) {
            continue;
        }
        Group tempGroup;

        for (auto filename : group) {
            tempGroup.addFile(filename);
        }

//        while(!group.empty()){
//            tempGroup.addFile(group.top());
//            group.pop();
//        }
        result.push_back(tempGroup);
        result[count].setGroupName("group_" + std::to_string(count));
        ++count;
    }
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

// основная логика по распределению тем(точка входа)
void AnalizerImpl::analize() {
    move();
}
