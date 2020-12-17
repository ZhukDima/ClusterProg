#include "GroupImpl.h"

void GroupImpl::setGroupName(const std::string &inputGroupName) {
    groupName = inputGroupName;
}

void GroupImpl::addFile(const std::string &fileName) {
    files.push_back(fileName);
}

std::string GroupImpl::getGroupName() const {
    return groupName;
}

const std::vector<std::string>& GroupImpl::getFiles() const {
    return files;
}

GroupImpl::GroupImpl(const GroupImpl& obj) {
    groupName = obj.getGroupName();
    files = obj.getFiles();
}

GroupImpl& GroupImpl::operator=(const GroupImpl& obj){
    if (this == &obj) {
        return *this;
    }
    groupName = obj.getGroupName();
    files = obj.getFiles();
    return *this;
}
