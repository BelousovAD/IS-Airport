#include "ticketdialog.h"
#include "ui_ticketdialog.h"

TicketDialog::TicketDialog(QWidget *parent, Ticket *ticket,
                           Flight *flight, User *mCurUser) :
    QDialog(parent),
    ui(new Ui::TicketDialog)
{
    ui->setupUi(this);
    ui->titleLine->setValue(ticket->getNumber());
    ui->arrivalPointLine->setText(flight->getArrivalPoint());
    ui->dateAndTimeArrivalLine->setDateTime(flight->getArrivalDateTime());
    ui->dateAndTimeDepartureLine->setDateTime(flight->getDepartureDateTime());
    ui->departurePointLine->setText(flight->getDeparturePoint());
    ui->midnameLine->setText(mCurUser->getMidname());
    ui->nameLine->setText(mCurUser->getName());
    ui->numberLine->setValue(flight->getNumber());
    ui->passportNumberLine->setText(QString::number(mCurUser->getPassportNumber()));
    ui->passportSerialLine->setText(QString::number(mCurUser->getPassportSerial()));
    ui->surnameLine->setText(mCurUser->getSurname());
}

TicketDialog::~TicketDialog()
{
    delete ui;
}
