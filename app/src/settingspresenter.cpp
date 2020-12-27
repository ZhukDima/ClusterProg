#include "settingspresenter.h"

SettingsPresenter::SettingsPresenter(const Settings &settings)
{
    this->settings = settings;
}

QStringList SettingsPresenter::getChoosenFilesFromFileDialog()
{
    QStringList files = QFileDialog::getOpenFileNames(nullptr,
                                                      "Choose files",
                                                      settings.startDir,
                                                      "Text files (*.txt *.md);;XML files (*.xml);; HTML files (*.html)");
    return files;
}

Settings SettingsPresenter::setChoosenFiles(const QStringList &files)
{
    settings.choosenFiles = files;
    return settings;
}

Settings SettingsPresenter::setStartDirFromFileDialog()
{
    QString dir = QFileDialog::getExistingDirectory(nullptr, "Open Directory",
                                                    settings.startDir,
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty()) {
        settings.startDir = dir;
    }
    return settings;
}

Settings SettingsPresenter::clearChoosenFiles()
{
    settings.choosenFiles.clear();
    return settings;
}

std::string SettingsPresenter::getChoosenDirToOperate()
{
    return this->settings.startDir.toStdString();
}