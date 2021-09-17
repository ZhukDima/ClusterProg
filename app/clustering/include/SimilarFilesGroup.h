#ifndef CLUSTERPROG_GROUP_HPP
#define CLUSTERPROG_GROUP_HPP

#include <string>
#include <vector>

class SimilarFilesGroupImpl;

class SimilarFilesGroup {
public:
    SimilarFilesGroup();

    SimilarFilesGroup(const SimilarFilesGroup &obj);

    ~SimilarFilesGroup();

    SimilarFilesGroup &operator=(const SimilarFilesGroup &obj);

    void setGroupName(const std::string &inputGroupName);

    void addFile(const std::string &fileName);

    [[nodiscard]] const std::string &getGroupName() const;

    [[nodiscard]] const std::vector<std::string> &getFiles() const;

    [[nodiscard]] SimilarFilesGroupImpl getImpl() const;

private:
    SimilarFilesGroupImpl *impl = nullptr;
};

#endif //CLUSTERPROG_GROUP_HPP
