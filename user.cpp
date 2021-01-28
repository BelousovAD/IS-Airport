#include "user.h"

User::User()
{
}

User::~User()
{
}

const QString &User::getLogin() const
{
    return mLogin;
}

void User::setLogin(const QString &login)
{
    mLogin = login;
}

const QString &User::getPassword() const
{
    return mPassword;
}

void User::setPassword(const QString &password)
{
    mPassword = password;
}

const QString &User::getSurname() const
{
    return mSurname;
}

void User::setSurname(const QString &surname)
{
    mSurname = surname;
}

const QString &User::getName() const
{
    return mName;
}

void User::setName(const QString &name)
{
    mName = name;
}

const QString &User::getMidname() const
{
    return mMidname;
}

void User::setMidname(const QString &midname)
{
    mMidname = midname;
}

const QString &User::getPassportSerial() const
{
    return mPassportSerial;
}

void User::setPassportSerial(const QString &passportSerial)
{
    mPassportSerial = passportSerial;
}

const QString &User::getPassportNumber() const
{
    return mPassportNumber;
}

void User::setPassportNumber(const QString &passportNumber)
{
    mPassportNumber = passportNumber;
}

const QDate &User::getDateLogin() const
{
    return mDateLogin;
}

void User::setDateLogin(const QDate &dateLogin)
{
    mDateLogin = dateLogin;
}

void User::save(QDataStream &ost) const
{
    ost << mLogin << mPassword << mSurname
        << mName << mMidname << mPassportSerial
        << mPassportNumber << mDateLogin;
}

void User::load(QDataStream &ist)
{
    ist >> mLogin >> mPassword >> mSurname
        >> mName >> mMidname >> mPassportSerial
        >> mPassportNumber >> mDateLogin;
}
