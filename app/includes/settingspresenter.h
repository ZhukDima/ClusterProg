#ifndef SETTINGSPRESENTER_H
#define SETTINGSPRESENTER_H

#include "settings.h"

class SettingsPresenter
{
public:
    SettingsPresenter(const Settings &settings);

    Settings setStartDirFromFileDialog();

    QStringList getChoosenFilesFromFileDialog();

    Settings setChoosenFiles(const QStringList &files);

    Settings clearChoosenFiles();

    const int getClusterCountFromDialog(QWidget* dialogParent, bool &ok);

    Settings setClusterCount(const int &clusterCount);

    std::string getChoosenDirToOperate() const;

    std::vector<std::string> getChoosenFilesToOperate() const;

    int getClusterCountToOperate() const;

private:
    Settings settings;
};

#endif // SETTINGSPRESENTER_H
