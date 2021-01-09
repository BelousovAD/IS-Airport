#include "ticketwindow.h"
#include "ui_ticketwindow.h"

TicketWindow::TicketWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicketWindow)
{
    ui->setupUi(this);
}

TicketWindow::~TicketWindow()
{
    delete ui;
}
