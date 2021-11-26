#include "appselection.h"
#include "ui_appselection.h"
#include "controller.h"

#include <QFileDialog>

AppSelection::AppSelection(QWidget *parent) :
    Dialog(parent),
    ui(new Ui::AppSelection)
{
    ui->setupUi(this);
    auto app = Controller::getInstalledApps();
    for (int i = 0; i < (int)app->size(); i++)
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(app->at(i)->name());
        item->setIcon(QIcon::fromTheme(app->at(i)->icon()));
        ui->appListsWidget->addItem(item);
    }
}

AppSelection::~AppSelection()
{
    delete ui;
}

void AppSelection::on_cancel_clicked()
{
    close();
}

void AppSelection::on_otherApp_clicked()
{
    ui->appListsWidget->setCurrentRow(-1);
    //std::unique_ptr<Shortcut> s(new Shortcut);
    Shortcut shortcut;

    shortcut.setPath(QFileDialog::getOpenFileName(this,
                                            "Select an executable or script",
                                            QDir::homePath()));

    emit fileChoosed(shortcut);
    close();
}

void AppSelection::on_ok_clicked()
{
    if (ui->appListsWidget->currentRow() >= 0)
    {
        std::unique_ptr<Shortcut> s = std::move(Controller::getInstalledApps()
                                                    ->at(ui->appListsWidget->currentRow()));
        emit fileChoosed(*s.release());
    }
    close();
}
