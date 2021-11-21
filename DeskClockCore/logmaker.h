#ifndef LOGMAKER_H
#define LOGMAKER_H

#include <QString>
#include <QDir>
#include <QFile>

#include "deskClockCore_global.h"

class DESKCLOCKCORE_EXPORT Log{
public:
    static void log(const QString &message)
    {
#ifdef __linux__
        QString configPath = QDir::homePath() + "/.clockdesktop/"
#elif _WIN32
        QString configPath = QDir::homePath() + "/clockdesktop/";
#endif
        QDir dir;

        if (!dir.exists(configPath))
            dir.mkdir(configPath);
        QFile file("log.txt");
        if (file.open(QFile::Append))
        {
            file.write(message.toStdString().c_str());
        }

        file.close();
    }
};

#endif // LOGMAKER_H
