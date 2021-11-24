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


#include "shortcutdao.h"
#include "deskclockexception.h"
#include "logmaker.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

ShortcutDao::ShortcutDao(QSqlDatabase &database, QObject *parent)
    : QObject(parent), mDatabase(database)
{

}

void ShortcutDao::init() const
{
    QSqlQuery query(mDatabase);
    QString shortcutSql("CREATE TABLE IF NOT EXISTS shortcut("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "name TEXT NOT NULL, "
                        "path TEXT, "
                        "icon TEXT, "
                        "args TEXT)");
    if (!query.exec(shortcutSql))
    {
        qDebug() << query.lastError();
        Log::log(query.lastError().text());
    }
}

std::unique_ptr<std::vector<std::unique_ptr<Shortcut> > > ShortcutDao::getShortcuts() const
{
    QSqlQuery query("SELECT * FROM shortcut", mDatabase);
    query.exec();
    std::unique_ptr<std::vector<std::unique_ptr<Shortcut>>> list(
        new std::vector<std::unique_ptr<Shortcut>>
        );
    while (query.next())
    {
        std::unique_ptr<Shortcut> shortcut(new Shortcut);
        shortcut->setId(query.value("id").toInt());
        shortcut->setName(query.value("name").toString());
        shortcut->setPath(query.value("path").toString());
        shortcut->setIcon(query.value("icon").toString());
        shortcut->setArgs(query.value("args").toString());

        list->push_back(std::move(shortcut));
    }

    return list;
}

bool ShortcutDao::addShortcut(Shortcut &shortcut) const
{
    qDebug() << shortcutCount();
    if (shortcutCount() == 6)
        throw ShortcutFullException();
    qDebug() << "Args: " << shortcut.args();
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO shortcut("
                  "name, "
                  "path, "
                  "icon, "
                  "args) "
                  "VALUES(:name, :path, :icon, :args)");
    query.bindValue(":name", shortcut.name());
    query.bindValue(":path", shortcut.path());
    query.bindValue(":icon", shortcut.icon());
    query.bindValue(":args", shortcut.args());

    if (!query.exec())
    {
        qDebug() << "Error while saving shortcut: " << query.lastError();
        Log::log(query.lastError().text());
        return false;
    }
    else
    {
        mDatabase.commit();
        shortcut.setId(query.lastInsertId().toInt());
        return true;
    }
}

bool ShortcutDao::remove(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM shortcut WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec())
    {
        mDatabase.commit();
        return true;
    }
    qDebug() << "Error while deleting shortcut " << id;
    Log::log(query.lastError().text());
    return false;

}

bool ShortcutDao::update(Shortcut &shortcut) const
{
    qDebug() << "Updating " << shortcut.id();
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE shortcut SET "
                  "name = :name, "
                  "path = :path, "
                  "icon = :icon, "
                  "args = :args "
                  "WHERE id = :id");
    query.bindValue(":name", shortcut.name());
    query.bindValue(":path", shortcut.path());
    query.bindValue(":icon", shortcut.icon());
    query.bindValue(":args", shortcut.args());
    query.bindValue(":id", shortcut.id());

    if (query.exec())
    {
        mDatabase.commit();
        return true;
    }
    qDebug() << "Error while updating " << shortcut.name() << "\n[ERR] " << query.lastError();
    Log::log(query.lastError().text());
    return false;
}

int ShortcutDao::shortcutCount() const
{
    QSqlQuery query(mDatabase);
    if (query.exec("SELECT COUNT(*) FROM shortcut")){
        query.next();
        return query.value(0).toInt();
    }
    Log::log(query.lastError().text());
    return -1;
}
