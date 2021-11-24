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


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include <QTime>
#include <QDate>
#include <QDebug>
#include <QScrollBar>
#include <QMenu>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint
                   | Qt::SplashScreen
                   /*| Qt::WindowStaysOnBottomHint*/);
    setAttribute(Qt::WA_TranslucentBackground);
    //setAttribute(Qt::WA_DeleteOnClose);
    setTrayIcon();
    ui->setupUi(this);
    setTime();
    timer = new QTimer;
    timer->setInterval(1000);
    timer->start();
    connect(timer, &QTimer::timeout, this, &MainWindow::setTime);
    this->setUi();
    //setMaximumSize(400, 800);
    setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (previousPos_y < 20)
    {
        QCursor curs(Qt::SizeAllCursor);
        setCursor(curs);
        move(e->globalX() - previousPos_x, e->globalY() - previousPos_y);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    previousPos_x = e->x();
    previousPos_y = e->y();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu menu(this);
    menu.addAction("About", this, &MainWindow::openAbout);
    menu.addAction("Close", this, &MainWindow::close);
    menu.exec(e->globalPos());
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->y() < 20 && e->button() == Qt::LeftButton)
        setCursor(Qt::ArrowCursor);
}

void MainWindow::setTime()
{
    QTime time = QTime::currentTime();
    ui->timeLabel->setText(time.toString("hh:mm:ss"));
    QDate date = QDate::currentDate();
    ui->dateLabel->setText(date.toString("dd MMMM yyyy\ndddd"));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    qDebug() << width() << " : " << height();
    QSettings settings;
    settings.setValue("mainwindow/geometry", geometry());
    settings.sync();
    trayIcon->hide();
    //event->accept();
    QApplication::exit();
}

void MainWindow::openAbout()
{
    About *about = new About;
    about->show();
}

/*void MainWindow::onBringFront()
{
    qDebug() << windowFlags();
    //setWindowFlag(Qt::WindowStaysOnTopHint);
    activateWindow();
    raise();
}*/

void MainWindow::setUi()
{
    auto shortcuts = Controller::getShortcuts();
    for (int i = 0; i < 6; i++)
    {
        ShortcutButton *sButton = new ShortcutButton;
        if (i < (int)shortcuts->size())
            sButton->setShortcut(*shortcuts->at(i));
        int row = i < 3 ? 0 : 1;
        int col = i % 3;
        ui->shortcutLayout->addWidget(sButton, row, col);

    }
    todoListView = new TodoListView;
    ui->todoLayout->addWidget(todoListView);

    //setAttribute(Qt::WA_NoSystemBackground);
    //ui->listWidget->verticalScrollBar()->setVisible(false);

    QSettings setting;
    if (setting.contains("mainwindow/geometry"))
    {
        qDebug() << setting.value("mainwindow/geometry").toRect();
        setGeometry(setting.value("mainwindow/geometry").toRect());
    }
}

void MainWindow::setTrayIcon()
{
    QIcon icon(":/icons/shortcut.png");
    trayIcon = new QSystemTrayIcon(icon);
    QMenu *menu = new QMenu;
    //menu->addAction("Bring Up", this, &MainWindow::onBringFront);
    menu->addAction("About", this, &MainWindow::openAbout);
    menu->addAction("Close", this, &MainWindow::close);
    trayIcon->setContextMenu(menu);
    trayIcon->show();

    QObject::connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::onTrayIconActivated);
}

void MainWindow::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    qDebug() << "Tray activated. " << reason;
    if (reason == QSystemTrayIcon::Trigger)
    {
        trayIcon->contextMenu()->show();
    }
}
