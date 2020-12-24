#include "settings.h"

Settings::Settings() : startDir(Settings::DEFAULT_DIR),
                       clusterCount(0)
{
}

const QString Settings::DEFAULT_DIR = QDir::homePath();

const int Settings::MIN_CLUSTER_COUNT = 2;