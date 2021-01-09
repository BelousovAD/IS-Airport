#ifndef TICKET_H
#define TICKET_H

#include <QString>

class Ticket
{
public:
    //! Конструктор по умолчанию
    Ticket();
    //! Создаёт объект Ticket с параметрами.
    Ticket(qint32 number, qint32 flightNumber, QString passengerLogin);
    //! Возвращает номер билета.
    const qint32 &getNumber() const;
    //! Устанавливает номер билета.
    void setNumber(const QString &number);
    //! Возвращает номер рейса.
    const QString &getFlightNumber() const;
    //! Устанавливает номер рейса.
    void setFlightNumber(const QString &flightNumber);
    //! Возвращает логин пассажира.
    const QString &getPassengerLogin() const;
    //! Устанавливает логин пассажира.
    void setPassengerLogin(const QString &passengerLogin);
    //! Сохраняет билет в поток ost.
    void save(QDataStream &ost) const;
    //! Загружает билет из потока ist.
    void load(QDataStream &ist);
private:
    //! Номер билета
    qint32 mNumber;
    //! Номер рейса
    qint32 mFlightNumber;
    //! Логин пассажира
    QString mPassengerLogin;
};

//! Реализация оператора << для вывода Ticket в QDataStream.
inline QDataStream &operator<<(QDataStream &ost, const Ticket &ticket)
{
    ticket.save(ost);
    return ost;
}

//! Реализация оператора >> для вввода Ticket из QDataStream.
inline QDataStream &operator>>(QDataStream &ist, Ticket &ticket)
{
    ticket.load(ist);
    return ist;
}

#endif // TICKET_H
