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


#ifndef SHORTCUTDIALOG_H
#define SHORTCUTDIALOG_H

#include <QWidget>
#include <QMouseEvent>
#include "shortcut.h"

namespace Ui {
class ShortcutDialog;
}

class ShortcutDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ShortcutDialog(QWidget *parent = nullptr);
    ~ShortcutDialog();

    void setFormData(const Shortcut &shortcut);

    void mouseMoveEvent(QMouseEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;


private slots:
    void on_executablePathButton_clicked();

    void on_chooseIconButton_clicked();

    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::ShortcutDialog *ui;

    int previous_x;
    int previous_y;

signals:
    void shortcutValidated(Shortcut &shortcut);
};

#endif // SHORTCUTDIALOG_H
