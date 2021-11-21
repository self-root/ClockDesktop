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


#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "deskClockCore_global.h"
#include "tododao.h"
#include "shortcutdao.h"

#include <QObject>


class QSqlDatabase;

class DESKCLOCKCORE_EXPORT DatabaseManager : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase *mDatabase;

public:
    explicit DatabaseManager(QObject *parent = nullptr);
    static DatabaseManager &instance();

    const ToDoDao toDoDao;
    const ShortcutDao shortcutDao;
};

#endif // DATABASEMANAGER_H
