#include <Analizer.h>
#include <AnalizerImpl.h>

#include <utility>

Analizer::Analizer(std::string inputPathToDirectory, std::vector<std::string> inputPathsToFiles,
                   std::string inputPathToResult, size_t inputCountDirectory) : impl(
        new AnalizerImpl(std::move(inputPathToDirectory), std::move(inputPathsToFiles), std::move(inputPathToResult),
                         inputCountDirectory)) {}

std::vector<SimilarFilesGroup> Analizer::categorize() {
    return impl->categorize();
}

int Analizer::filesMoving() {
    impl->filesMoving();
}

std::vector<VectorSpace<double>> Analizer::getFileInfo(const std::vector<FileInfo> &filesInfo) const {
    return impl->getFileInfo(filesInfo);
}

std::vector<std::vector<std::string>> Analizer::getClusteringData(const std::vector<FileInfo> &filesInfo) const {
    return impl->getClusteringData(filesInfo);
}
