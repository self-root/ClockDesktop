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


#ifndef SHORTCUTDAO_H
#define SHORTCUTDAO_H

#include "deskClockCore_global.h"
#include "shortcut.h"

#include <QObject>
#include <vector>
#include <memory>

class QSqlDatabase;

class DESKCLOCKCORE_EXPORT ShortcutDao : public QObject
{
    Q_OBJECT
public:
    explicit ShortcutDao(QSqlDatabase &database, QObject *parent = nullptr);
    void init() const;
    /**
     * getShortcuts: Read shortcut info from database
     *
     * @return an unique_ptr vector containing the shortcuts
     */
    std::unique_ptr<std::vector<std::unique_ptr<Shortcut>>> getShortcuts() const;

    /**
     * Add new shortct into the database
     *
     * @param shortcut  The Shortcut object to be added
     * @return return True if the insertion was successful.
     */
    bool addShortcut(Shortcut &shortcut) const;

    /**
     * @brief Delete a shortcut from the database
     * @param id    The Id of the shortcut to be removed
     * @return True if it was successful
     */
    bool remove(int id) const;

    /**
     * @brief Update a shortcut in the database
     * @param shortcut  The Shortcut opject to be updates
     * @return True if ok
     */
    bool update(Shortcut &shortcut) const;

    /**
     * @brief shortcutCount: Get the number of shortcut saved in the database
     * @return int, the number of shortcut
     */
    int shortcutCount() const;
private:
    QSqlDatabase &mDatabase;

};

#endif // SHORTCUTDAO_H
