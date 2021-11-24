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


#include "todomodel.h"

TodoModel::TodoModel(QObject *parent)
    : QAbstractListModel(parent)
{
    todoList = DatabaseManager::instance().toDoDao.getTodo();
}


int TodoModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return todoList->size();
}

QVariant TodoModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        return todoList->at(index.row())->title();
    }
    if (role == Qt::ToolTipRole)
        return todoList->at(index.row())->description();
    return QVariant();
}

bool TodoModel::addTodo(ToDo &todo)
{
    if (DatabaseManager::instance().toDoDao.add(todo))
    {
        beginInsertRows(QModelIndex(), todoList->size(), todoList->size());
        std::unique_ptr<ToDo> tmp(new ToDo);
        tmp->setId(todo.id());
        tmp->setTitle(todo.title());
        tmp->setDescription(todo.description());
        todoList->push_back(std::move(tmp));
        endInsertRows();
        return true;
    }
    return false;
}

bool TodoModel::updateTodo(const QModelIndex &modelIndex, ToDo &todo)
{
    todo.setId(todoList->at(modelIndex.row())->id());
    if (DatabaseManager::instance().toDoDao.update(todo))
    {
        todoList->at(modelIndex.row())->setTitle(todo.title());
        todoList->at(modelIndex.row())->setDescription(todo.description());
        emit dataChanged(modelIndex, modelIndex);
        return true;
    }

    return false;
}

bool TodoModel::todoDone(const QModelIndex &modelIndex)
{
    todoList->at(modelIndex.row())->setDone(1);
    if (DatabaseManager::instance().toDoDao.update(todoList->at(modelIndex.row())))
    {
        beginRemoveRows(QModelIndex(), modelIndex.row()-1, modelIndex.row()-1);
        todoList->erase(todoList->begin()+modelIndex.row());
        endRemoveRows();
        return true;
    }
    return false;
}

/**bool TodoModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
}

bool TodoModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}**/
