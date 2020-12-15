#include "settings.h"

Settings::Settings() : dir("/home")
{}

void Settings::setDir(const QString &dir)
{
    this->dir = dir;
}

void Settings::setFiles(const QStringList &files)
{
    this->files = files;
}

QString Settings::getStartDir() const
{
    return this->dir;
}

QStringList Settings::getChoosenFiles() const
{
    return this->files;
}
