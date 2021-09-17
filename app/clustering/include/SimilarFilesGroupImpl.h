#ifndef CLUSTERPROG_SIMILARFILESGROUPIMPL_H
#define CLUSTERPROG_SIMILARFILESGROUPIMPL_H

#include <SimilarFilesGroup.h>

class SimilarFilesGroupImpl {
public:
    SimilarFilesGroupImpl() = default;
    SimilarFilesGroupImpl(const SimilarFilesGroupImpl& obj) = default;
    SimilarFilesGroupImpl& operator=(const SimilarFilesGroupImpl& obj) = default;
    ~SimilarFilesGroupImpl() = default;

    void setGroupName(const std::string &inputGroupName);

    void addFile(const std::string &fileName);

    [[nodiscard]] const std::string &getGroupName() const;

    [[nodiscard]] const std::vector<std::string>& getFiles() const;

private:
    std::string groupName;
    std::vector<std::string> files;
};

#endif //CLUSTERPROG_SIMILARFILESGROUPIMPL_H
