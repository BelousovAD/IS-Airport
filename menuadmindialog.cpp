#include "menuadmindialog.h"
#include "ui_menuadmindialog.h"

MenuAdminDialog::MenuAdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuAdminDialog)
{
    ui->setupUi(this);
}

MenuAdminDialog::~MenuAdminDialog()
{
    delete ui;
}
