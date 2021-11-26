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


#include "todolistview.h"
#include <QMenu>
#include <QDebug>
#include <QScrollBar>

#include "tododialog.h"

TodoListView::TodoListView(QWidget *parent)
    : QListView(parent)
{
    todoModel = new TodoModel;
    setModel(todoModel);
    verticalScrollBar()->setVisible(false);
}

void TodoListView::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu menu(this);
    menu.addAction("New", this, &TodoListView::onNew);
    menu.addAction("Edit", this, &TodoListView::onEdit)->setDisabled(!itemSelected());
    menu.addAction("Done", this, &TodoListView::onDone)->setDisabled(!itemSelected());

    menu.exec(e->globalPos());
}

void TodoListView::onNew()
{
    TodoDialog *dialog = new TodoDialog;
    QObject::connect(dialog, &TodoDialog::todoValidated, this, &TodoListView::onAddNew);
    dialog->show();
}

void TodoListView::onEdit()
{
    qDebug() << selectedIndexes().at(0).row();
    TodoDialog *dialog = new TodoDialog;
    dialog->setFieldsValue(selectedIndexes().at(0));
    QObject::connect(dialog, &TodoDialog::todoValidated, this, &TodoListView::onUpdate);
    dialog->show();

}

void TodoListView::onDone()
{
    todoModel->todoDone(selectedIndexes().at(0));
}

void TodoListView::onAddNew(ToDo &todo)
{
    todoModel->addTodo(todo);
    qDebug() << "Adding todo";
}

void TodoListView::onUpdate(ToDo &todo)
{
    todoModel->updateTodo(selectedIndexes().at(0), todo);
}

bool TodoListView::itemSelected()
{
    QModelIndexList selected_ = selectedIndexes();
    return !selected_.empty();
}
