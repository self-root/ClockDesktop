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

/*
    This class works as a bridge between this library(mostly the database)
    and the UI(User interface)
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <vector>
#include <memory>
#include <shortcut.h>
#include <unistd.h>

#include "deskClockCore_global.h"
#include "shortcut.h"
#include "databasemanager.h"

class DESKCLOCKCORE_EXPORT Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

    std::unique_ptr<std::vector<std::unique_ptr<Shortcut>>> shortcuts;

    static std::unique_ptr<std::vector<std::unique_ptr<Shortcut>>> getShortcuts();

    /**
     * @brief Excecute the program/script associated with the shortcut
     * @param shortcut  the shortcut to be executed
     */
    static void open(const Shortcut &shortcut);

    static bool saveShortcut(Shortcut &shortcut);

    static bool removeShortcut(int id);

    static bool updateShortcut(Shortcut &shortcut);

};

#endif // CONTROLLER_H
