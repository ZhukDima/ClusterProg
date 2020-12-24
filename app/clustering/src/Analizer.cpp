#include <Analizer.h>
#include <AnalizerImpl.h>

Analizer::Analizer() : impl(new AnalizerImpl) {}

void Analizer::setCountDirectory(size_t inputCountDirectory) {
    impl->setCountDirectory(inputCountDirectory);
}

void Analizer::setPathToResult(const std::string &inputPathToResult) {
    impl->setPathToResult(inputPathToResult);
}

void Analizer::setPathToDirectory(const std::string &inputPathToDirectory) {
    impl->setPathToDirectory(inputPathToDirectory);
}

std::vector<Group> Analizer::categorize() {
    return impl->categorize();
}

void Analizer::move() {
    impl->move();
}

void Analizer::analize() {
    impl->analize();
}

void Analizer::setPathsToFiles(const std::vector<std::string> &inputPathsToFiles) {
    impl->setPathsToFiles(inputPathsToFiles);
}