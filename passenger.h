#ifndef PASSENGER_H
#define PASSENGER_H

#include "user.h"

#include <QSet>

class Passenger:public User
{
public:
    Passenger();
    Passenger(QString login, QString password, QString surname,
          QString name, QString midname, qint32 passportSerial,
          qint32 passportNumber, QDate dateLogin, QSet<qint32> tickets);
    ~Passenger();
    //! Вставляет номер билета в set.
    void add(qint32 number);
    //! Удаляет номер билета из set.
    void del(qint32 number);
private:
    QSet<qint32> tickets;
};

#endif // PASSENGER_H
