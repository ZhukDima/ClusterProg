#include <map>
#include <string>
#include "FileInfo.h"
#include "FileInfoImpl.h"

FileInfo::FileInfo(): impl(new FileInfoImpl()) {}

FileInfo::FileInfo(std::string _pathToFile): impl(std::make_unique<FileInfoImpl>(_pathToFile)) {}

FileInfo::FileInfo(std::string _pathToFile, const std::map<std::wstring, double>& _metric):
        impl(std::make_unique<FileInfoImpl>(_pathToFile, _metric)) {}

FileInfo::FileInfo(const FileInfo& obj): impl(std::make_unique<FileInfoImpl>(obj.getImpl())) {}

FileInfo& FileInfo::operator=(const FileInfo& obj) {
    if (this == &obj) {
        return *this;
    }
    *impl = obj.getImpl();
    return *this;
}

std::string FileInfo::getPath() const {
    return impl->getPath();
}

FileInfoImpl FileInfo::getImpl() const {
    return *impl;
}

int FileInfo::getAmountOfWords() const {
    return impl->getAmountOfWords();
}

const std::map<std::wstring, double>& FileInfo::getAllMetric() const {
    return impl->getAllMetric();
}

void FileInfo::setMetric(std::wstring key, double value) {
    impl->setMetric(key, value);
}

FileInfo::~FileInfo() {
    FileInfoImpl *p = impl.release();
    delete p;
}