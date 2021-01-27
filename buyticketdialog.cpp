#include "buyticketdialog.h"
#include "ui_buyticketdialog.h"

#include <QMessageBox>

BuyTicketDialog::BuyTicketDialog(QWidget *parent, Flight *mCurFlight,
                                 UsersBook *mUsersbook, TicketsBook *mTicketsbook,
                                 QVector<QPair<int, int>> *ticketAndPassenger) :
    QDialog(parent),
    ui(new Ui::BuyTicketDialog)
{
    ui->setupUi(this);
    this->mCurFlight = mCurFlight;
    this->mUsersbook = mUsersbook;
    this->mTicketsbook = mTicketsbook;
    this->ticketAndPassenger = ticketAndPassenger;
}

BuyTicketDialog::~BuyTicketDialog()
{
    delete ui;
}

void BuyTicketDialog::on_rejectButton_clicked()
{
    QDialog::reject();
}

void BuyTicketDialog::on_acceptButton_clicked()
{
    User *user;
    QPair<int, int> pair;
    //if()
    for (int i = 0; i < (*mUsersbook).size(); ++i)
    {
        user = (*mUsersbook)[i];
        if (user->getLogin() == ui->loginLine->text())
        {
            if (dynamic_cast<Passenger*>(user))
            {
                if (QString::number(user->getPassportSerial()) == ui->passportSerialLine->text())
                {
                    if (QString::number(user->getPassportNumber()) == ui->passportNumberLine->text())
                    {
                        if (user->getSurname() == ui->surnameLine->text())
                        {
                            if (user->getName() == ui->nameLine->text())
                            {
                                if (user->getMidname() == ui->midnameLine->text())
                                {
                                    pair.second = i;
                                    break;
                                }
                            }
                        }
                    }
                }
                QMessageBox::warning(this, windowTitle(), "Пользователь с таким логином зарегистрирован\nи его личные данные не совпадают с указанными");
                return;
            }
            else
            {
                QMessageBox::warning(this, windowTitle(), "Пользователь с таким логином зарегистрирован\nи не является пассажиром");
                return;
            }
        }
        else if (i == (*mUsersbook).size() - 1)
        {
            Passenger *passenger = new Passenger;
            passenger->setLogin(ui->loginLine->text());
            passenger->setSurname(ui->surnameLine->text());
            passenger->setName(ui->nameLine->text());
            passenger->setMidname(ui->midnameLine->text());
            passenger->setPassportSerial(ui->passportSerialLine->text().toInt());
            passenger->setPassportNumber(ui->passportNumberLine->text().toInt());
            passenger->setPassword("12345");
            (*mUsersbook).insert(*passenger);
            QMessageBox::information(this, windowTitle(), QString("Пассажир успешно зарегистрирован\nПассажиром успешно приобретён билет\n\n") +
                                     "Для входа в систему пассажиру предоставлены следующие данные:\nЛогин: " + ui->loginLine->text() +
                                     "\nПароль: 12345");
            pair.second = i;
        }
    }
    Ticket *ticket = new Ticket();
    ticket->setDepartureDate(ui->dateDepartureLine->date());
    ticket->setPassengerLogin(user->getLogin());
    ticket->setNumber((*mTicketsbook).size() + 1);
    ticket->setFlightNumber(mCurFlight->getNumber());
    if (mCurFlight->getDepartureTime().addSecs(1800) >= mCurFlight->getArrivalTime())
    {
        ticket->setArrivalDate(ui->dateDepartureLine->date().addDays(1));
    }
    else
    {
        ticket->setArrivalDate(ui->dateDepartureLine->date());
    }
    pair.first = (*mTicketsbook).size();
    (*mTicketsbook).insert(*ticket);
    ticketAndPassenger->push_back(pair);
    mCurFlight->setNumberTickets(mCurFlight->getNumberTickets() + 1);
    QMessageBox::information(this, windowTitle(), "Пассажиром успешно приобретён билет");
    QDialog::accept();
}
