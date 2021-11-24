#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include "dialog.h"

namespace Ui {
class About;
}

class About : public Dialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private slots:
    void on_pushButton_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
