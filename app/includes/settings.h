#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QStringList>
#include <QDebug>
#include <QDir>

class Settings
{
public:
    Settings();
    ~Settings() {}
    Settings &operator=(const Settings &other) = default;

    QStringList choosenFiles;
    QString startDir;
    int clusterCount;

    static const QString DEFAULT_DIR;
    static const int MIN_CLUSTER_COUNT;
};

#endif // SETTINGS_H
