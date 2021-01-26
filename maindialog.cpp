#include "maindialog.h"
#include "ui_maindialog.h"

#include <QMessageBox>

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
        QTableWidgetItem *item_number = new QTableWidgetItem(QString::number(flight.getNumber()));
        QTableWidgetItem *item_departurePoint = new QTableWidgetItem(flight.getDeparturePoint());
        QTableWidgetItem *item_arrivalPoint = new QTableWidgetItem(flight.getArrivalPoint());
        QTableWidgetItem *item_departureTime = new QTableWidgetItem(flight.getDepartureTime().toString("hh:mm"));
        QTableWidgetItem *item_arrivalTime = new QTableWidgetItem(flight.getArrivalTime().toString("hh:mm"));
        QTableWidgetItem *item_mark = new QTableWidgetItem(flight.getMark());
        QTableWidgetItem *item_numberSeats = new QTableWidgetItem(QString::number(flight.getNumberSeats()));
        QTableWidgetItem *item_numberFreeSeats = new QTableWidgetItem(QString::number(flight.getNumberSeats() - flight.getTicketNumbers().size()));

        ui->flightTableWidget->insertRow(i);
        ui->flightTableWidget->setItem(i, 0, item_number);
        ui->flightTableWidget->setItem(i, 1, item_departurePoint);
        ui->flightTableWidget->setItem(i, 2, item_arrivalPoint);
        ui->flightTableWidget->setItem(i, 3, item_departureTime);
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
    mMenuDialog = new MenuDialog(this, mCurUser, mUsersbook, mFlightsbook, mTicketsbook);
    mMenuDialog->open();
}


void MainDialog::on_addButton_clicked()
{
    mAddFlightDialog = new AddFlightDialog(this, mFlightsbook);
    mAddFlightDialog->setWindowTitle("Добавление рейса");
    connect(mAddFlightDialog, SIGNAL(accepted()), this, SLOT(addFlightToTable()));
    mAddFlightDialog->open();
}

void MainDialog::addFlightToTable()
{
    int row = ui->flightTableWidget->rowCount();
    Flight *flight = (*mFlightsbook)[row];
    QTableWidgetItem *item_number = new QTableWidgetItem(QString::number(flight->getNumber()));
    QTableWidgetItem *item_departurePoint = new QTableWidgetItem(flight->getDeparturePoint());
    QTableWidgetItem *item_arrivalPoint = new QTableWidgetItem(flight->getArrivalPoint());
    QTableWidgetItem *item_departureTime = new QTableWidgetItem(flight->getDepartureTime().toString("hh:mm"));
    QTableWidgetItem *item_arrivalTime = new QTableWidgetItem(flight->getArrivalTime().toString("hh:mm"));
    QTableWidgetItem *item_mark = new QTableWidgetItem(flight->getMark());
    QTableWidgetItem *item_numberSeats = new QTableWidgetItem(QString::number(flight->getNumberSeats()));
    QTableWidgetItem *item_numberEmptySeats = new QTableWidgetItem(QString::number(flight->getNumberSeats() - flight->getTicketNumbers().size()));
    ui->flightTableWidget->insertRow(row);
    ui->flightTableWidget->setItem(row, 0, item_number);
    ui->flightTableWidget->setItem(row, 1, item_departurePoint);
    ui->flightTableWidget->setItem(row, 2, item_arrivalPoint);
    ui->flightTableWidget->setItem(row, 3, item_departureTime);
    ui->flightTableWidget->setItem(row, 4, item_arrivalTime);
    ui->flightTableWidget->setItem(row, 5, item_mark);
    ui->flightTableWidget->setItem(row, 6, item_numberSeats);
    ui->flightTableWidget->setItem(row, 7, item_numberEmptySeats);
}

void MainDialog::editFlightAtTable()
{
    int row = ui->flightTableWidget->currentRow();
    ui->flightTableWidget->removeRow(row);
    Flight *flight = (*mFlightsbook)[row];
    QTableWidgetItem *item_number = new QTableWidgetItem(QString::number(flight->getNumber()));
    QTableWidgetItem *item_departurePoint = new QTableWidgetItem(flight->getDeparturePoint());
    QTableWidgetItem *item_arrivalPoint = new QTableWidgetItem(flight->getArrivalPoint());
    QTableWidgetItem *item_departureTime = new QTableWidgetItem(flight->getDepartureTime().toString("hh:mm"));
    QTableWidgetItem *item_arrivalTime = new QTableWidgetItem(flight->getArrivalTime().toString("hh:mm"));
    QTableWidgetItem *item_mark = new QTableWidgetItem(flight->getMark());
    QTableWidgetItem *item_numberSeats = new QTableWidgetItem(QString::number(flight->getNumberSeats()));
    QTableWidgetItem *item_numberEmptySeats = new QTableWidgetItem(QString::number(flight->getNumberSeats() - flight->getTicketNumbers().size()));
    ui->flightTableWidget->insertRow(row);
    ui->flightTableWidget->setItem(row, 0, item_number);
    ui->flightTableWidget->setItem(row, 1, item_departurePoint);
    ui->flightTableWidget->setItem(row, 2, item_arrivalPoint);
    ui->flightTableWidget->setItem(row, 3, item_departureTime);
    ui->flightTableWidget->setItem(row, 4, item_arrivalTime);
    ui->flightTableWidget->setItem(row, 5, item_mark);
    ui->flightTableWidget->setItem(row, 6, item_numberSeats);
    ui->flightTableWidget->setItem(row, 7, item_numberEmptySeats);
}

void MainDialog::on_delButton_clicked()
{
    int currentRow = ui->flightTableWidget->currentRow();
    if (currentRow != -1) {
        (*mFlightsbook).erase(currentRow);
        ui->flightTableWidget->removeRow(currentRow);
    }
    else {
        QMessageBox::warning(this, windowTitle(), "Не выбран ни один пользователь");
    }
}

void MainDialog::on_editButton_clicked()
{
    mAddFlightDialog = new AddFlightDialog(this, mFlightsbook, ui->flightTableWidget->currentRow());
    mAddFlightDialog->setWindowTitle("Редактирование рейса");
    connect(mAddFlightDialog, SIGNAL(accepted()), this, SLOT(editFlightAtTable()));
    mAddFlightDialog->open();
}
