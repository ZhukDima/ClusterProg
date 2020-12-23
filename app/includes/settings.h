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
    Settings& operator=(const Settings& other) = default;

    QStringList choosenFiles;
    QString startDir;

    static const QString DEFAULT_DIR;
};

#endif // SETTINGS_H
