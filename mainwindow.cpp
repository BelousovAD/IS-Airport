#include "mainwindow.h"
#include "menuwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, User *mCurUser,
                       UsersBook *mUsersbook, FlightsBook *mFlightsbook,
                       TicketsBook *mTicketsbook) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mCurUser = mCurUser;
    this->mUsersbook = mUsersbook;
    this->mFlightsbook = mFlightsbook;
    this->mTicketsbook = mTicketsbook;
    if (dynamic_cast<Admin*>(mCurUser) == nullptr)
    {
        ui->addButton->hide();
        ui->delButton->hide();
        ui->editButton->hide();
    }
    for (int i = 0; i < (*mFlightsbook).size(); ++i)
    {
        Flight flight = (*mFlightsbook)[i];
        QTableWidgetItem *item_number = new QTableWidgetItem(flight.getNumber());
        QTableWidgetItem *item_departurePoint = new QTableWidgetItem(flight.getDeparturePoint());
        QTableWidgetItem *item_arrivalPoint = new QTableWidgetItem(flight.getArrivalPoint());
        QTableWidgetItem *item_departureTime = new QTableWidgetItem(flight.getDepartureTime().toString());
        QTableWidgetItem *item_arrivalTime = new QTableWidgetItem(flight.getArrivalTime().toString());
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menuButton_clicked()
{

}
