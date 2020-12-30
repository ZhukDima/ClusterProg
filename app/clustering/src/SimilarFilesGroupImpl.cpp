#include "SimilarFilesGroupImpl.h"

void SimilarFilesGroupImpl::setGroupName(const std::string &inputGroupName) {
    groupName = inputGroupName;
}

void SimilarFilesGroupImpl::addFile(const std::string &fileName) {
    files.push_back(fileName);
}

const std::string &SimilarFilesGroupImpl::getGroupName() const {
    return groupName;
}

const std::vector<std::string> &SimilarFilesGroupImpl::getFiles() const {
    return files;
}
