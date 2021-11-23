/*
    ClockDesktop
    Copyright (C) Root_

    This file is part of ClockDesktop.
    ClockDesktop is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ClockDesktop is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ClockDesktop.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "databasemanager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include "logmaker.h"

#include <QSqlError>
#include <QDebug>
#include <QDir>

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject(parent), mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))
    , toDoDao(*mDatabase), shortcutDao(*mDatabase)
{
#ifdef __linux__
    QString dbpath = QDir::homePath() + "/.clockdesktop/";
    QDir dbdir(dbpath);
    if(!dbdir.exists())
    {
        dbdir.mkdir(dbpath);
    }
    qDebug() << dbpath;
#elif _WIN32
    QString dbpath = QDir::homePath() + "/clockdesktop/";
    QDir dbdir(dbpath);
    if(!dbdir.exists())
    {
        dbdir.mkdir(dbpath);
    }
    qDebug() << dbpath;
#endif
    mDatabase->setDatabaseName(dbpath + "todoclock.db");
    if (!mDatabase->open())
    {
        Log::log(mDatabase->lastError().text());
        qDebug() << mDatabase->lastError();
    }

    toDoDao.init();
    shortcutDao.init();
}

DatabaseManager &DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}
