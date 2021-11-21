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


#ifndef SHORTCUTBUTTON_H
#define SHORTCUTBUTTON_H

#include <QPushButton>
#include <QObject>
#include <QContextMenuEvent>
#include "shortcut.h"
#include "shortcutdialog.h"

class ShortcutButton : public QPushButton
{
    Q_OBJECT
public:
    ShortcutButton(QWidget *parent=nullptr);

    void setShortcut(const Shortcut &shortcut_, bool reset=false);

    void newShortCut();
    void editShortcut();
    void mousePressEvent(QMouseEvent *e) override;
    void contextMenuEvent(QContextMenuEvent *e) override;

private:
    Shortcut mShortcut;
public slots:
    void removeShortcut();
    void onShortcutValidated(Shortcut &shortcut);
    void onShortcutEdit(Shortcut &shortcut);
};

#endif // SHORTCUTBUTTON_H
