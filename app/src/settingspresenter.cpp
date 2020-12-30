#include "settingspresenter.h"

#include <QFileDialog>
#include <QInputDialog>
#include <string>
#include <vector>
#include <filesystem>
#include "Analizer.h"

namespace fs = std::filesystem;

SettingsPresenter::SettingsPresenter(const Settings &settings)
{
    this->settings = settings;
}

QStringList SettingsPresenter::getChoosenFilesFromFileDialog() const
{
    QStringList files = QFileDialog::getOpenFileNames(nullptr,
                                                      "Choose files",
                                                      settings.startDir,
                                                      "Text files (*.txt)");
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
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty())
    {
        settings.startDir = dir;
    }
    return settings;
}

Settings SettingsPresenter::clearChoosenFiles()
{
    settings.choosenFiles.clear();
    return settings;
}

std::string SettingsPresenter::getStartDirToOperate() const
{
    return settings.startDir.toStdString();
}

std::vector<std::string> SettingsPresenter::getChoosenFilesToOperate() const
{
    std::vector<std::string> preparedToOperateChoosenFiles;
    for (auto file : settings.choosenFiles)
        preparedToOperateChoosenFiles.push_back(file.toStdString());
    return preparedToOperateChoosenFiles;
}

const int SettingsPresenter::getClusterCountFromDialog(QWidget *dialogParent, bool &ok) const
{
    int clusterCount = QInputDialog::getInt(dialogParent,
                                            "Cluster count",
                                            "Input count of clusters",
                                            Settings::MIN_CLUSTER_COUNT,
                                            Settings::MIN_CLUSTER_COUNT,
                                            INT_MAX,
                                            1,
                                            &ok);
    return clusterCount;
}

int SettingsPresenter::getClusterCountToOperate() const
{
    return settings.clusterCount;
}

Settings SettingsPresenter::setClusterCount(const int &clusterCount)
{
    settings.clusterCount = clusterCount;
    return settings;
}

Settings SettingsPresenter::updateStartDirIfChoosenFilesFromAnother()
{
    if (settings.choosenFiles.empty())
        return settings;

    fs::path filePath = settings.choosenFiles.first().toStdString();

    if (filePath.parent_path().string() == settings.startDir.toStdString())
        return settings;

    settings.startDir = QString::fromStdString(filePath.parent_path().string());

    return settings;
}

bool SettingsPresenter::isValidSettings()
{
    return (!settings.choosenFiles.empty() || settings.startDir != Settings::DEFAULT_DIR);
}

int SettingsPresenter::useAnalizer()
{
    Analizer analizer(getStartDirToOperate(), getChoosenFilesToOperate(),
                      getStartDirToOperate(), getClusterCountToOperate());
    return analizer.filesMoving();
}