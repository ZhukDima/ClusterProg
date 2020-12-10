#ifndef CLUSTERPROG_GROUP_HPP
#define CLUSTERPROG_GROUP_HPP

#include <string>
#include <vector>

class GroupImpl;

// множество файлов с общей темой
class Group {
public:
    Group();

    ~Group();

    void setGroupName(const std::string &inputGroupName);

    void addFile(const std::string &fileName);

    const std::string &getGroupName() const;

    const std::vector<std::string> &getFiles() const;

private:
    GroupImpl *impl = nullptr;
};

#endif //CLUSTERPROG_GROUP_HPP
