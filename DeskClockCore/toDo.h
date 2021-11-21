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


#ifndef DESKCLOCKCORE_H
#define DESKCLOCKCORE_H

#include <QObject>

#include "deskClockCore_global.h"

class DESKCLOCKCORE_EXPORT ToDo : public QObject
{
private:
    int mId;
    QString mTitle;
    QString mDescription;
    bool mDone;
public:
    ToDo(QObject *parent=nullptr);

    QString title() const;
    void setTitle(const QString &title);
    QString description() const;
    void setDescription(const QString &description);
    bool done() const;
    void setDone(bool done);
    int id() const;
    void setId(int id);

    bool isValid() const;
};

#endif // DESKCLOCKCORE_H
