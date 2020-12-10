#include "GroupImpl.h"

void GroupImpl::setGroupName(const std::string &inputGroupName) {
    groupName = inputGroupName;
}

void GroupImpl::addFile(const std::string &fileName) {
    files.push_back(fileName);
}

const std::string &GroupImpl::getGroupName() const {
    return groupName;
}

const std::vector<std::string> &GroupImpl::getFiles() const {
    return files;
}
