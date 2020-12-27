#include <AnalizerImpl.h>

AnalizerImpl::AnalizerImpl(std::string inputPathToDirectory, std::vector<std::string> inputPathsToFiles,
                           std::string inputPathToResult, size_t inputCountDirectory) : pathToDirectory(
        std::move(inputPathToDirectory)), pathsToFiles(std::move(inputPathsToFiles)), pathToResult(
        std::move(inputPathToResult)), countDirectory(inputCountDirectory) {}

std::string cutName(const std::string &path) {
    return std::filesystem::path(path).filename();
}

std::vector<SimilarFilesGroup> AnalizerImpl::categorize() {
    DirHandler *directory = nullptr;
    if (pathsToFiles.empty()) {
        directory = new DirHandler(pathToDirectory);
    } else {
        directory = new DirHandler(pathsToFiles);
    }
    auto filesInfo = directory->getFiles(); // получаем vector<FileInfo>
    TFIDFPP tfidf(filesInfo);
    auto setUnicWords = tfidf.getSetUsefulUnicWords(); // set уникальных слов в директории
    std::vector<VectorSpace<double>> vectorsSpace; // создаем вектор векторных простарнств
    for (const auto &fileInfo : filesInfo) {
        vectorsSpace.emplace_back(setUnicWords.size());
        size_t i = 0;
        for (const auto &word : setUnicWords) {
            vectorsSpace.back()[i++] = tfidf.calculateTFIDFMetric(word, fileInfo.getPath()); // метрика для каждого уникального слова в директории
        }
    }
    KMeans<VectorSpace<double>> kMeans(vectorsSpace);
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
    std::vector<SimilarFilesGroup> result;
    size_t count = 0;
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
    delete directory;
    return result;
}

void AnalizerImpl::filesMoving() {
    std::vector<SimilarFilesGroup> groups = categorize();
    for (const auto &group : groups) {
        FileManager::createDir(pathToResult + "/" + group.getGroupName());
        for (const auto &filename : group.getFiles()) {
            FileManager::moveFile(filename, pathToResult + "/" + group.getGroupName() + "/" + cutName(filename));
        }
    }
}
