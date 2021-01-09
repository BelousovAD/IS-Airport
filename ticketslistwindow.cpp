#include "ticketslistwindow.h"
#include "ui_ticketslistwindow.h"

TicketsListWindow::TicketsListWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicketsListWindow)
{
    ui->setupUi(this);
}

TicketsListWindow::~TicketsListWindow()
{
    delete ui;
}
