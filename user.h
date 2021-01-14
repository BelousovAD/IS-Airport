#ifndef USER_H
#define USER_H

#include <QDate>
#include <QString>

class User
{
public:
    //! Создаёт объект User с параметрами.
    explicit User(QString login = "", QString password = "", QString surname = "",
         QString name = "", QString midname = "", qint32 passportSerial = NULL,
         qint32 passportNumber = NULL, QDate dateLogin = QDate::currentDate());
    //! Деструктор.
    ~User();
    //! Возвращает логин пользователя.
    const QString &getLogin() const;
    //! Устанавливает логин пользователя.
    void setLogin(const QString &login);
    //! Возвращает пароль пользователя.
    const QString &getPassword() const;
    //! Устанавливает пароль пользователя.
    void setPassword(const QString &text);
    //! Возвращает фамилию пользователя.
    const QString &getSurname() const;
    //! Устанавливает фамилию пользователя.
    void setSurname(const QString &text);
    //! Возвращает имя пользователя.
    const QString &getName() const;
    //! Устанавливает имя пользователя.
    void setName(const QString &text);
    //! Возвращает отчество пользователя.
    const QString &getMidname() const;
    //! Устанавливает отчество пользователя.
    void setMidname(const QString &text);
    //! Возвращает серию паспорта пользователя.
    const qint32 &getPassportSerial() const;
    //! Устанавливает серию паспорта пользователя.
    void setPassportSerial(const qint32 &passportSerial);
    //! Возвращает номер паспорта пользователя.
    const qint32 &getPassportNumber() const;
    //! Устанавливает номер паспорта пользователя.
    void setPassportNumber(const qint32 &passportSerial);
    //! Возвращает дату последнего входа пользователя.
    const QDate &getDateLogin() const;
    //! Устанавливает дату последнего входа пользователя.
    void setDateLogin(const QDate &dateLogin);
    //! Сохраняет пользователя в поток ost.
    void save(QDataStream &ost) const;
    //! Загружает пользователя из потока ist.
    void load(QDataStream &ist);
private:
    //! Логин пользователя
    QString mLogin;
    //! Пароль пользователя
    QString mPassword;
    //! Фамилия пользователя
    QString mSurname;
    //! Имя пользователя
    QString mName;
    //! Отчество пользователя
    QString mMidname;
    //! Серия паспорта пользователя
    qint32 mPassportSerial;
    //! Номер паспорта пользователя
    qint32 mPassportNumber;
    //! Дата последнего входа пользователя
    QDate mDateLogin;
};

//! Реализация оператора << для вывода User в QDataStream.
inline QDataStream &operator<<(QDataStream &ost, const User &user)
{
    user.save(ost);
    return ost;
}

//! Реализация оператора >> для вввода User из QDataStream.
inline QDataStream &operator>>(QDataStream &ist, User &user)
{
    user.load(ist);
    return ist;
}

#endif // USER_H
