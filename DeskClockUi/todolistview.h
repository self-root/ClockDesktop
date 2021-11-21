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


#ifndef TODOLISTVIEW_H
#define TODOLISTVIEW_H

#include <QListView>
#include <QContextMenuEvent>

#include "todomodel.h"

class TodoListView : public QListView
{
    Q_OBJECT
public:
    TodoListView(QWidget *parent=nullptr);

    TodoModel *todoModel = nullptr;

    void contextMenuEvent(QContextMenuEvent *e) override;

    void onNew();
    void onEdit();
    void onDone();

public slots:
    void onAddNew(ToDo &todo);
    void onUpdate(ToDo &todo);
private:
    bool itemSelected();
};

#endif // TODOLISTVIEW_H
