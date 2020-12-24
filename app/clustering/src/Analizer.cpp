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

void Analizer::filesMoving() {
    impl->filesMoving();
}
