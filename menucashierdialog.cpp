#include "menucashierdialog.h"
#include "ui_menucashierdialog.h"

MenuCashierDialog::MenuCashierDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuCashierDialog)
{
    ui->setupUi(this);
}

MenuCashierDialog::~MenuCashierDialog()
{
    delete ui;
}
