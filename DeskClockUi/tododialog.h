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


#ifndef TODODIALOG_H
#define TODODIALOG_H

#include "dialog.h"
#include <QModelIndex>
#include <QMouseEvent>
#include "toDo.h"

namespace Ui {
class TodoDialog;
}

class TodoDialog : public Dialog
{
    Q_OBJECT

public:
    explicit TodoDialog(QWidget *parent = nullptr);
    ~TodoDialog();
    void setFieldsValue(const QModelIndex &modelIndex);

private:
    Ui::TodoDialog *ui;

signals:
    void todoValidated(ToDo &todo);
private slots:
    void on_save_clicked();
    void on_cancel_clicked();
};

#endif // TODODIALOG_H
