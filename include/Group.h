#ifndef CLUSTERPROG_GROUP_HPP
#define CLUSTERPROG_GROUP_HPP

#include <string>
#include <vector>

class Group {
private:
    std::string groupName;
    std::vector<std::string> files;
public:
    Group();

    ~Group();

    void setGroupName(std::string inputGroupName);

    void addFile(std::string fileName);

    std::string getGroupName();

    std::vector<std::string> getFiles();
};

#endif //CLUSTERPROG_GROUP_HPP
