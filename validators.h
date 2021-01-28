#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <QValidator>

namespace Validators
{
    const QRegExpValidator loginValidator(QRegExp("^\\w{5,20}$"));
    const QRegExpValidator passwordValidator(QRegExp("^\\w{5,20}$"));
    const QRegExpValidator surnameValidator(QRegExp("^[А-Я][а-я]+$"));
    const QRegExpValidator nameValidator(QRegExp("^[А-Я][а-я]+$"));
    const QRegExpValidator midnameValidator(QRegExp("^([А-Я][а-я]+)?$"));
    const QRegExpValidator passportSerialValidator(QRegExp("^\\d{4,4}$"));
    const QRegExpValidator passportNumberValidator(QRegExp("^\\d{6,6}$"));
    const QRegExpValidator departurePointValidator(QRegExp("^[гспд]\.\\s[А-Я]([а-я]|-)+$"));
    const QRegExpValidator arrivalPointValidator(QRegExp("^[гспд]\.\\s[А-Я]([а-я]|-)+$"));
    const QRegExpValidator markValidator(QRegExp("^\\S+$"));
}

#endif // VALIDATORS_H
