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


#include "toDo.h"

bool ToDo::done() const
{
    return mDone;
}

void ToDo::setDone(bool done)
{
    mDone = done;
}

int ToDo::id() const
{
    return mId;
}

void ToDo::setId(int id)
{
    mId = id;
}

bool ToDo::isValid() const
{
    return !mTitle.isEmpty();
}

ToDo::ToDo(QObject *parent)
    : QObject(parent)
{
    mDone = 0;
}

QString ToDo::title() const
{
    return mTitle;
}

void ToDo::setTitle(const QString &title)
{
    mTitle = title;
}

QString ToDo::description() const
{
    return mDescription;
}

void ToDo::setDescription(const QString &description)
{
    mDescription = description;
}
