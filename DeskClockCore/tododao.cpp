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


#include "tododao.h"
#include "databasemanager.h"
#include "logmaker.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

ToDoDao::ToDoDao(QSqlDatabase &database, QObject *parent)
    : QObject(parent), mDatabase(database)
{

}

void ToDoDao::init() const
{
    if(!mDatabase.tables().contains("todo"))
    {
        QSqlQuery query(mDatabase);
        QString toDoTableSql("CREATE TABLE IF NOT EXISTS todo("
                             "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                             "title TEXT NOT NULL, "
                             "description TEXT, "
                             "done INTEGER DEFAULT 0 "
                             ")");
        if (!query.exec(toDoTableSql))
        {
            qDebug() << query.lastError();
            Log::log(query.lastError().text());
        }
    }
}

std::unique_ptr<std::vector<std::unique_ptr<ToDo> > > ToDoDao::getTodo() const
{
    QSqlQuery query("SELECT * FROM todo WHERE done = 0", mDatabase);
    query.exec();
    std::unique_ptr<std::vector<std::unique_ptr<ToDo>>> list(new std::vector<std::unique_ptr<ToDo>>);

    while (query.next())
    {
        std::unique_ptr<ToDo> td(new ToDo);
        td->setId(query.value("id").toInt());
        td->setTitle(query.value("title").toString());
        td->setDescription(query.value("description").toString());
        td->setDone(query.value("done").toBool());

        list->push_back(std::move(td));
    }
    return list;
}

bool ToDoDao::add(ToDo &todo) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO todo("
                  "title, description) "
                  "VALUES(:title, :desc)");
    query.bindValue(":title", todo.title());
    query.bindValue(":desc", todo.description());
    if (query.exec())
    {
        todo.setId(query.lastInsertId().toInt());
        return true;
    }

    qDebug() << "Error while inserting " << todo.title() << " > " << query.lastError();
    Log::log(query.lastError().text());
    return false;
}

bool ToDoDao::remove(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM todo WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec())
    {
        mDatabase.commit();
        return true;
    }
    qDebug() << "Error while Deleting " << id << " > " << query.lastError();
    Log::log(query.lastError().text());
    return false;
}

bool ToDoDao::update(ToDo &todo) const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE todo SET "
                  "title = :title, "
                  "description = :desc, "
                  "done = :done WHERE id = :id");
    query.bindValue(":title", todo.title());
    query.bindValue(":desc", todo.description());
    query.bindValue(":done", todo.done());
    query.bindValue(":id", todo.id());

    if (query.exec())
    {
        mDatabase.commit();
        return true;
    }
    qDebug() << "Error while updating " << todo.title() << " > " << query.lastError();
    Log::log(query.lastError().text());
    return false;
}

bool ToDoDao::update(std::unique_ptr<ToDo> &todo) const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE todo SET "
                  "title = :title, "
                  "description = :desc, "
                  "done = :done WHERE id = :id");
    query.bindValue(":title", todo->title());
    query.bindValue(":desc", todo->description());
    query.bindValue(":done", todo->done());
    query.bindValue(":id", todo->id());

    if (query.exec())
    {
        mDatabase.commit();
        return true;
    }
    qDebug() << "Error while updating " << todo->title() << " > " << query.lastError();
    Log::log(query.lastError().text());
    return false;
}
