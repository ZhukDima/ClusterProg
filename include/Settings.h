#include <vector>
#include <string>
#include <set>
#include <utility>

class Settings
{
private:
    std::vector<std::string> importantThemes;
    std::vector<std::pair<std::string, std::set<std::string>>> unionThemes;
public:
    void addImportantTheme(std::string importantTheme);
    void joinThemes(std::pair<std::string, std::set<std::string>> themes);
    void applyChanges();
};