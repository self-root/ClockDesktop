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


#ifndef SHORTCUT_H
#define SHORTCUT_H

#include <QObject>
#include <QString>

class Shortcut : public QObject
{
    Q_OBJECT
public:
    explicit Shortcut(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &name);

    const QString &path() const;
    void setPath(const QString &path);

    QString icon() const;
    void setIcon(const QString &icon);

    QString description() const;
    void setDescription(const QString &description);

    int id() const;
    void setId(int id);

    bool validShortcut() const;

    void clear();

    QString args() const;
    void setArgs(const QString &args);

private:
    int mId;
    QString mName;
    QString mPath;
    QString mIcon;
    QString mDescription;
    QString mArgs;

};

#endif // SHORTCUT_H
