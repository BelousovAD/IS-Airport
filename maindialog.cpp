#include "maindialog.h"
#include "ui_maindialog.h"
#include "addflightdialog.h"
#include "menucashierdialog.h"
#include "menudialog.h"

MainDialog::MainDialog(QWidget *parent, UsersBook *mUsersbook,
                       FlightsBook *mFlightsbook, TicketsBook *mTicketsbook,
                       User* mCurUser) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    this->mCurUser = mCurUser;
    this->mUsersbook = mUsersbook;
    this->mFlightsbook = mFlightsbook;
    this->mTicketsbook = mTicketsbook;
    this->mCurUser = mCurUser;
    if (dynamic_cast<Admin*>(mCurUser) == nullptr)
    {
        ui->addButton->hide();
        ui->delButton->hide();
        ui->editButton->hide();
    }
    // Конструирование таблицы
    for (int i = 0; i < (*mFlightsbook).size(); ++i)
    {
        Flight flight = *(*mFlightsbook)[i];
        QTableWidgetItem *item_number = new QTableWidgetItem(flight.getNumber());
        QTableWidgetItem *item_departurePoint = new QTableWidgetItem(flight.getDeparturePoint());
        QTableWidgetItem *item_arrivalPoint = new QTableWidgetItem(flight.getArrivalPoint());
        QTableWidgetItem *item_departureTime = new QTableWidgetItem(flight.getDepartureDateTime().time().toString());
        QTableWidgetItem *item_arrivalTime = new QTableWidgetItem(flight.getArrivalDateTime().time().toString());
        QTableWidgetItem *item_mark = new QTableWidgetItem(flight.getMark());
        QTableWidgetItem *item_numberSeats = new QTableWidgetItem(flight.getNumberSeats());
        QTableWidgetItem *item_numberFreeSeats = new QTableWidgetItem(flight.getNumberSeats() - flight.getTicketNumbers().size());

        ui->flightTableWidget->insertRow(i);
        ui->flightTableWidget->setItem(i, 0, item_number);
        ui->flightTableWidget->setItem(i, 1, item_departurePoint);
        ui->flightTableWidget->setItem(i, 2, item_departureTime);
        ui->flightTableWidget->setItem(i, 3, item_arrivalPoint);
        ui->flightTableWidget->setItem(i, 4, item_arrivalTime);
        ui->flightTableWidget->setItem(i, 5, item_mark);
        ui->flightTableWidget->setItem(i, 6, item_numberSeats);
        ui->flightTableWidget->setItem(i, 7, item_numberFreeSeats);
    }
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_menuButton_clicked()
{
    MenuDialog menudialog(this, mCurUser, mUsersbook, mFlightsbook, mTicketsbook);
    menudialog.exec();
}

