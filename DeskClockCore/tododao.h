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


#ifndef TODODAO_H
#define TODODAO_H

#include "deskClockCore_global.h"
#include "toDo.h"

#include <QObject>
#include <vector>
#include <memory>

class QSqlDatabase;

class DESKCLOCKCORE_EXPORT ToDoDao : public QObject
{
    Q_OBJECT
public:
    explicit ToDoDao(QSqlDatabase &database ,QObject *parent = nullptr);
    void init() const;
    std::unique_ptr<std::vector<std::unique_ptr<ToDo>>> getTodo() const;
    bool add(ToDo &todo) const;
    bool remove(int id) const;
    bool update(ToDo &todo) const;
    bool update(std::unique_ptr<ToDo> &todo) const;
private:
    QSqlDatabase &mDatabase;


};

#endif // TODODAO_H
