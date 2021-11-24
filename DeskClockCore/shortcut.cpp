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


#include "shortcut.h"
#include <QFileInfo>

Shortcut::Shortcut(QObject *parent)
    : QObject(parent), mId(-1)
{

}

QString Shortcut::name() const
{
    return mName;
}

void Shortcut::setName(const QString &name)
{
    mName = name;
}

const QString &Shortcut::path() const
{
    return mPath;
}

void Shortcut::setPath(const QString &path)
{
    mPath = path;
}

QString Shortcut::icon() const
{
    return mIcon;
}

void Shortcut::setIcon(const QString &icon)
{
    mIcon = icon;
}

QString Shortcut::description() const
{
    return mDescription;
}

void Shortcut::setDescription(const QString &description)
{
    mDescription = description;
}

int Shortcut::id() const
{
    return mId;
}

void Shortcut::setId(int id)
{
    mId = id;
}

bool Shortcut::validShortcut() const
{
    return (!mName.isEmpty() and !mPath.isEmpty());
}

void Shortcut::clear()
{
    mId = -1;
    mName = "";
    mPath = "";
    mDescription = "";
    mIcon = "";
    mArgs = "";
}

QString Shortcut::args() const
{
    return mArgs;
}

void Shortcut::setArgs(const QString &args)
{
    mArgs = args;
}
