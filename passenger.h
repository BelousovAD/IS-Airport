#ifndef PASSENGER_H
#define PASSENGER_H

#include "user.h"

#include <QSet>

class Passenger:public User
{
public:
    //! Создаёт объект Passenger с параметрами.
    explicit Passenger(QString login, QString password, QString surname,
          QString name, QString midname, qint32 passportSerial,
          qint32 passportNumber, QDate dateLogin, QSet<qint32> tickets);
    //! Деструктор.
    ~Passenger();
    //! Вставляет номер билета в set.
    void add(qint32 number);
    //! Удаляет номер билета из set.
    void del(qint32 number);
private:
    //! Внутренний контейнер для хранения номеров билетов.
    QSet<qint32> tickets;
};

#endif // PASSENGER_H
