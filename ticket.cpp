#include "ticket.h"

Ticket::Ticket()
{
}

Ticket::~Ticket()
{
}

const int &Ticket::getNumber() const
{
    return mNumber;
}

void Ticket::setNumber(const int &number)
{
    mNumber = number;
}

const int &Ticket::getFlightNumber() const
{
    return mFlightNumber;
}

void Ticket::setFlightNumber(const int &flightNumber)
{
    mFlightNumber = flightNumber;
}

const QString &Ticket::getPassengerLogin() const
{
    return mPassengerLogin;
}

void Ticket::setPassengerLogin(const QString &passengerLogin)
{
    mPassengerLogin = passengerLogin;
}

void Ticket::save(QDataStream &ost) const
{
    ost << mNumber << mFlightNumber << mPassengerLogin;
}

void Ticket::load(QDataStream &ist)
{
    ist >> mNumber >> mFlightNumber >> mPassengerLogin;
}
