#include <AnalizerImpl.h>

AnalizerImpl::AnalizerImpl(std::string inputPathToDirectory, std::vector<std::string> inputPathsToFiles,
                           std::string inputPathToResult, size_t inputCountDirectory) : pathToDirectory(
        std::move(inputPathToDirectory)), pathsToFiles(std::move(inputPathsToFiles)), pathToResult(
        std::move(inputPathToResult)), countDirectory(inputCountDirectory) {}

std::string cutName(const std::string &path) {
    return std::filesystem::path(path).filename();
}

std::vector<VectorSpace<double>> AnalizerImpl::getFileInfo(const std::vector<FileInfo> &filesInfo) const {
    TFIDFPP tfidf(filesInfo);
    auto setUnicWords = tfidf.getSetUsefulUnicWords();
    std::vector<VectorSpace<double>> vectorsSpace;
    for (const auto &fileInfo : filesInfo) {
        vectorsSpace.emplace_back(setUnicWords.size());
        size_t i = 0;
        for (const auto &word : setUnicWords) {
            vectorsSpace.back()[i++] = tfidf.calculateTFIDFMetric(word, fileInfo.getPath());
        }
    }
    return vectorsSpace;
}

std::vector<std::vector<std::string>> AnalizerImpl::getClusteringData(const std::vector<FileInfo> &filesInfo) const {
    KMeans<VectorSpace<double>> kMeans(getFileInfo(filesInfo));
    auto clusters = kMeans.calculate(countDirectory, std::vector<VectorSpace<double>>());
    std::vector<std::string> allPath;
    allPath.reserve(filesInfo.size());
    for (const auto &fileInfo : filesInfo) {
        allPath.push_back(fileInfo.getPath());
    }
    std::vector<std::vector<std::string>> clusteringData;
    clusteringData.reserve(clusters.size());
    for (const auto &cluster : clusters) {
        clusteringData.push_back(cluster.getClusteringDataByData(allPath));
    }
    return clusteringData;
}

std::vector<SimilarFilesGroup> AnalizerImpl::categorize() {
    std::unique_ptr<DirHandler> directory;
    try {
        if (pathsToFiles.empty()) {
            directory = std::make_unique<DirHandler>(pathToDirectory);
        } else {
            directory = std::make_unique<DirHandler>(pathsToFiles);
        }
    } catch (const char *exception) {
        throw exception;
    }
    auto filesInfo = directory->getFiles();
    std::vector<SimilarFilesGroup> result;
    size_t count = 0;
    auto clusteringData = getClusteringData(filesInfo);
    for (const auto &group : clusteringData) {
        if (group.empty()) {
            continue;
        }
        SimilarFilesGroup tempGroup;
        for (const auto &filename : group) {
            tempGroup.addFile(filename);
        }
        result.push_back(tempGroup);
        result[count].setGroupName("group_" + std::to_string(count));
        ++count;
    }
    return result;
}

int AnalizerImpl::filesMoving() {
    std::vector<SimilarFilesGroup> groups;
    try {
        groups = categorize();
    } catch (const char *) {
        return -1;
    }
    for (const auto &group : groups) {
        try {
            FileManager::createDir(pathToResult + "/" + group.getGroupName());
        } catch (const std::runtime_error &) {
            return -1;
        }
        for (const auto &filename : group.getFiles()) {
            try {
                FileManager::moveFile(filename, pathToResult + "/" + group.getGroupName() + "/" + cutName(filename));
            } catch (const std::exception &) {
                return -1;
            }
        }
    }
    return 0;
}
