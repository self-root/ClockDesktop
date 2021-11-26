#ifndef APPSELECTION_H
#define APPSELECTION_H

#include <QWidget>
#include "dialog.h"

class Shortcut;

namespace Ui {
class AppSelection;
}

class AppSelection : public Dialog
{
    Q_OBJECT

public:
    explicit AppSelection(QWidget *parent = nullptr);
    ~AppSelection();

private slots:
    void on_cancel_clicked();

    void on_otherApp_clicked();

    void on_ok_clicked();

private:
    Ui::AppSelection *ui;
    //std::unique_ptr<Shortcut> selectedApp;

signals:
    //void fileChoosed(std::unique_ptr<Shortcut> &s);
    void fileChoosed(const Shortcut &s);
};

#endif // APPSELECTION_H
