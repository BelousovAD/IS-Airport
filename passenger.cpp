#include <passenger.h>

Passenger::Passenger()
{
}

Passenger::~Passenger()
{
}

void Passenger::add(int number)
{
    mTickets.insert(number);
}

void Passenger::del(int number)
{
    mTickets.erase(mTickets.find(number));
}

void Passenger::save(QDataStream &ost) const
{
    ost << mLogin << mPassword << mSurname
        << mName << mMidname << mPassportSerial
        << mPassportNumber << mDateLogin << mTickets;
}

void Passenger::load(QDataStream &ist)
{
    ist >> mLogin >> mPassword >> mSurname
        >> mName >> mMidname >> mPassportSerial
        >> mPassportNumber >> mDateLogin >> mTickets;
}
