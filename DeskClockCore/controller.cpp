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


#include "controller.h"
#include <QDebug>
#include <QProcess>

Controller::Controller(QObject *parent) : QObject(parent)
{
    shortcuts = DatabaseManager::instance().shortcutDao.getShortcuts();
}

std::unique_ptr<std::vector<std::unique_ptr<Shortcut> > > Controller::getShortcuts()
{
    return DatabaseManager::instance().shortcutDao.getShortcuts();
}

void Controller::open(const Shortcut &shortcut)
{
    QStringList args;
    if (!shortcut.args().isEmpty())
        args << shortcut.args().split(",");
    qDebug() << args;
    QProcess::startDetached(shortcut.path(), args);
}

bool Controller::saveShortcut(Shortcut &shortcut)
{
    return DatabaseManager::instance().shortcutDao.addShortcut(shortcut);
}

bool Controller::removeShortcut(int id)
{
    return DatabaseManager::instance().shortcutDao.remove(id);
}

bool Controller::updateShortcut(Shortcut &shortcut)
{
    return DatabaseManager::instance().shortcutDao.update(shortcut);
}

