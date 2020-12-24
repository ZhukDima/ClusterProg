#ifndef SETTINGSPRESENTER_H
#define SETTINGSPRESENTER_H

#include "settings.h"

class SettingsPresenter
{
public:
    SettingsPresenter(const Settings &settings);

    Settings setStartDirFromFileDialog();

    QStringList getChoosenFilesFromFileDialog() const;

    Settings setChoosenFiles(const QStringList &files);

    Settings clearChoosenFiles();

    const int getClusterCountFromDialog(QWidget *dialogParent, bool &ok) const;

    Settings setClusterCount(const int &clusterCount);

    Settings updateStartDirIfChoosenFilesFromAnother();

    std::string getStartDirToOperate() const;

    std::vector<std::string> getChoosenFilesToOperate() const;

    int getClusterCountToOperate() const;

    bool isValidSettings();

private:
    Settings settings;
};

#endif // SETTINGSPRESENTER_H