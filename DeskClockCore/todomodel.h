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


#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <memory>

#include "deskClockCore_global.h"
#include "toDo.h"
#include "databasemanager.h"

class DESKCLOCKCORE_EXPORT TodoModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit TodoModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    //bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool addTodo(ToDo &todo);

    bool updateTodo(const QModelIndex &modelIndex, ToDo &todo);

    bool todoDone(const QModelIndex &modelIndex);

    // Remove data:
    //bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    std::unique_ptr<std::vector<std::unique_ptr<ToDo>>> todoList;
};

#endif // TODOMODEL_H
