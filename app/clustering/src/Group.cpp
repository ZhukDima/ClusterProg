#include <Group.h>
#include <GroupImpl.h>

Group::Group() : impl(new GroupImpl) {}

Group::~Group() { delete impl; }

void Group::setGroupName(const std::string &inputGroupName) {
    impl->setGroupName(inputGroupName);
}

void Group::addFile(const std::string &fileName) {
    impl->addFile(fileName);
}

const std::string &Group::getGroupName() const {
    return impl->getGroupName();
}

const std::vector<std::string> &Group::getFiles() const {
    return impl->getFiles();
}
