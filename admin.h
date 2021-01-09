#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin:public User
{
public:
    Admin();
    Admin(QString login, QString password, QString surname,
          QString name, QString midname, qint32 passportSerial,
          qint32 passportNumber, QDate dateLogin);
    ~Admin();
};

#endif // ADMIN_H
