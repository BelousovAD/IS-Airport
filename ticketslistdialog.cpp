#include "ticketslistdialog.h"
#include "ui_ticketslistdialog.h"

TicketsListDialog::TicketsListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TicketsListDialog)
{
    ui->setupUi(this);
}

TicketsListDialog::~TicketsListDialog()
{
    delete ui;
}
