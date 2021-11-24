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


#include "tododialog.h"
#include "ui_tododialog.h"

#include <QMouseEvent>

TodoDialog::TodoDialog(QWidget *parent) :
    Dialog(parent),
    ui(new Ui::TodoDialog)
{
    setAttribute(Qt::WA_TranslucentBackground);
    ui->setupUi(this);
}

TodoDialog::~TodoDialog()
{
    delete ui;
}

void TodoDialog::setFieldsValue(const QModelIndex &modelIndex)
{
    ui->todoEdit->setText(modelIndex.data().toString());
    ui->descriptionEdit->setPlainText(modelIndex.data(Qt::ToolTipRole).toString());
}

void TodoDialog::on_save_clicked()
{
    ToDo todo;
    todo.setTitle(ui->todoEdit->text());
    todo.setDescription(ui->descriptionEdit->toPlainText());
    if (todo.isValid())
    {
        emit todoValidated(todo);
        close();
    }

}

void TodoDialog::on_cancel_clicked()
{
    close();
}
