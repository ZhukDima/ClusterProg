#ifndef SETTINGSPRESENTER_H
#define SETTINGSPRESENTER_H

#include <QString>
#include <QFileDialog>

#include <string>

#include "settings.h"

class SettingsPresenter
{
public:
    SettingsPresenter(const Settings &settings);

    Settings setStartDirFromFileDialog();

    QStringList getChoosenFilesFromFileDialog();

    Settings setChoosenFiles(const QStringList &files);

    Settings clearChoosenFiles();

    std::string getChoosenDirToOperate();

    // getChoosenFilesToOperate

private:
    Settings settings;
};

#endif // SETTINGSPRESENTER_H
