#include "about.h"
#include "ui_about.h"
#include <QFile>
#include <QString>
#include <QPixmap>

About::About(QWidget *parent) :
    Dialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    QPixmap logo(":/icons/shortcut.png");
    logo = logo.scaledToWidth(64);
    ui->logoDisplay->setPixmap(logo);

    QFile about(":/about.html");
    if (about.open(QFile::ReadOnly))
    {
        QString fileContent = about.readAll();
        ui->aboutTextView->setHtml(fileContent);
    }
}

About::~About()
{
    delete ui;
}

void About::on_pushButton_clicked()
{
    close();
}

