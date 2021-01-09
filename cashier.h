#ifndef CASHIER_H
#define CASHIER_H

#include "user.h"

class Cashier:public User
{
public:
    Cashier();
    Cashier(QString login, QString password, QString surname,
          QString name, QString midname, qint32 passportSerial,
          qint32 passportNumber, QDate dateLogin);
    ~Cashier();
};

#endif // CASHIER_H
