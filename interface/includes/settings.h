#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QStringList>

class Settings
{
public:
    Settings();
    ~Settings() {}
    Settings& operator=(const Settings& other) = delete;

    QStringList choosenFiles;
    QString startDir;
};

#endif // SETTINGS_H
