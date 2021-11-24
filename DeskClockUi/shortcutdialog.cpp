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


#include "shortcutdialog.h"
#include "ui_shortcutdialog.h"
#include <QFileDialog>

ShortcutDialog::ShortcutDialog(QWidget *parent) :
    Dialog(parent),
    ui(new Ui::ShortcutDialog)
{
    ui->setupUi(this);
}

ShortcutDialog::~ShortcutDialog()
{
    delete ui;
}

void ShortcutDialog::setFormData(const Shortcut &shortcut)
{
    ui->shortcutNameEdit->setText(shortcut.name());
    ui->executablePathEdit->setText(shortcut.path());
    ui->argList->setText(shortcut.args());
    ui->iconPathEdit->setText(shortcut.icon());
}

void ShortcutDialog::on_executablePathButton_clicked()
{
    QFileDialog fileDialog;
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setDirectory(QDir::homePath());

    QStringList fileNames;
    if (fileDialog.exec())
        fileNames = fileDialog.selectedFiles();
    if (!fileNames.empty())
        ui->executablePathEdit->setText(fileNames.first());
}

void ShortcutDialog::on_chooseIconButton_clicked()
{
    QFileDialog fileDialog;
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setDirectory(QDir::homePath());
    fileDialog.setNameFilter("Images (*.png *.ico *.jpg *.jpeg *.svg *.webp)");

    QStringList fileNames;
    if (fileDialog.exec())
        fileNames = fileDialog.selectedFiles();
    if (!fileNames.empty())
        ui->iconPathEdit->setText(fileNames.first());
}

void ShortcutDialog::on_cancelButton_clicked()
{
    close();
}

void ShortcutDialog::on_saveButton_clicked()
{
    Shortcut s;
    s.setName(ui->shortcutNameEdit->text());
    s.setPath(ui->executablePathEdit->text());
    s.setIcon(ui->iconPathEdit->text());
    s.setArgs(ui->argList->text());
    if (s.validShortcut())
    {
        emit shortcutValidated(s);
        close();
    }
}
