#include <SimilarFilesGroup.h>
#include <SimilarFilesGroupImpl.h>

SimilarFilesGroup::SimilarFilesGroup() : impl(new SimilarFilesGroupImpl) {}

SimilarFilesGroup::~SimilarFilesGroup() { delete impl; }

void SimilarFilesGroup::setGroupName(const std::string &inputGroupName) {
    impl->setGroupName(inputGroupName);
}

void SimilarFilesGroup::addFile(const std::string &fileName) {
    impl->addFile(fileName);
}

const std::string &SimilarFilesGroup::getGroupName() const {
    return impl->getGroupName();
}

const std::vector<std::string>& SimilarFilesGroup::getFiles() const {
    return impl->getFiles();
}

SimilarFilesGroupImpl SimilarFilesGroup::getImpl() const {
    return *impl;
}

SimilarFilesGroup::SimilarFilesGroup(const SimilarFilesGroup& obj): impl(new SimilarFilesGroupImpl(obj.getImpl())) {}

SimilarFilesGroup& SimilarFilesGroup::operator=(const SimilarFilesGroup& obj) {
    if (this == &obj) {
        return *this;
    }
    *impl = obj.getImpl();
    return *this;
}
