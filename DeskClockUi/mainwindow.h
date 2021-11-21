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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QHoverEvent>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <vector>
#include <memory>
#include "shortcut.h"
#include "shortcutbutton.h"
#include "controller.h"
#include "todolistview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mouseMoveEvent(QMouseEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void contextMenuEvent(QContextMenuEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

public slots:
    void setTime();
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Controller * controller;
    TodoListView *todoListView = nullptr;

    void setUi();

    int previousPos_x;
    int previousPos_y;

};
#endif // MAINWINDOW_H
