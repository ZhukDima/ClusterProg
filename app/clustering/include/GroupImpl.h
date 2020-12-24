#ifndef CLUSTERPROG_GROUPIMPL_H
#define CLUSTERPROG_GROUPIMPL_H

#include <Group.h>

class GroupImpl {
public:
    GroupImpl() = default;
    GroupImpl(const GroupImpl& obj) = default;
    GroupImpl& operator=(const GroupImpl& obj) = default;
    ~GroupImpl() = default;

    void setGroupName(const std::string &inputGroupName);

    void addFile(const std::string &fileName);

    const std::string &getGroupName() const;

    const std::vector<std::string>& getFiles() const;

private:
    std::string groupName;
    std::vector<std::string> files;
};

#endif //CLUSTERPROG_GROUPIMPL_H