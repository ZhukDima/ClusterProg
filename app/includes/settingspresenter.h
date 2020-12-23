#ifndef SETTINGSPRESENTER_H
#define SETTINGSPRESENTER_H

#include <QString>
#include <QFileDialog>

#include "settings.h"

class SettingsPresenter
{
public:
    SettingsPresenter(const Settings &settings);

    Settings setStartDirFromFileDialog();

    QStringList getChoosenFilesFromFileDialog();

    Settings setChoosenFiles(const QStringList &files);

    Settings clearChoosenFiles();

private:
    Settings settings;
};

#endif // SETTINGSPRESENTER_H
