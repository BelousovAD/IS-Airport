#include "flight.h"

Flight::Flight()
{
}

Flight::~Flight()
{
}

const int &Flight::getNumber() const
{
    return mNumber;
}

void Flight::setNumber(const int &number)
{
    mNumber = number;
}

const QString &Flight::getDeparturePoint() const
{
    return mDeparturePoint;
}

void Flight::setDeparturePoint(const QString &departurePoint)
{
    mDeparturePoint = departurePoint;
}

const QString &Flight::getArrivalPoint() const
{
    return mArrivalPoint;
}

void Flight::setArrivalPoint(const QString &arrivalPoint)
{
    mArrivalPoint = arrivalPoint;
}

const QTime &Flight::getDepartureTime() const
{
    return mDepartureTime;
}

void Flight::setDepartureTime(const QTime &departureTime)
{
    mDepartureTime = departureTime;
}

const QTime &Flight::getArrivalTime() const
{
    return mArrivalTime;
}

void Flight::setArrivalTime(const QTime &arrivalTime)
{
    mArrivalTime = arrivalTime;
}

const QString &Flight::getMark() const
{
    return mMark;
}

void Flight::setMark(const QString &mark)
{
    mMark = mark;
}

const int &Flight::getNumberSeats() const
{
     return mNumberSeats;
}

void Flight::setNumberSeats(const int &numberSeats)
{
    mNumberSeats = numberSeats;
}

const QVector<int> &Flight::getTicketNumbers() const
{
    return mTicketNumbers;
}

void Flight::setTicketNumbers(const QVector<int> &ticketNumbers)
{
    mTicketNumbers = ticketNumbers;
}

void Flight::save(QDataStream &ost) const
{
    ost << mNumber << mDeparturePoint << mArrivalPoint
        << mDepartureTime << mArrivalTime << mMark
        << mNumberSeats << mTicketNumbers;
}

void Flight::load(QDataStream &ist)
{
    ist >> mNumber >> mDeparturePoint >> mArrivalPoint
        >> mDepartureTime >> mArrivalTime >> mMark
        >> mNumberSeats >> mTicketNumbers;
}
