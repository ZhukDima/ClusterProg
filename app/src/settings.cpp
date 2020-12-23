#include "settings.h"

Settings::Settings() :
    startDir(Settings::DEFAULT_DIR)
{
}

const QString Settings::DEFAULT_DIR  = QDir::homePath();
