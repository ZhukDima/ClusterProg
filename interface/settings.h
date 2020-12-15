#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QStringList>


class Settings
{
public:
    Settings();
    ~Settings() {}
    const Settings& operator=(const Settings& other) = delete;
    void setDir(const QString& dir);
    void setFiles(const QStringList& files);
    QString getStartDir() const;
    QStringList getChoosenFiles() const;

private:
    QStringList files;
    QString dir;
};



#endif // SETTINGS_H
