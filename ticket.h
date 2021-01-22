#ifndef TICKET_H
#define TICKET_H

#include <QDataStream>
#include <QString>

class Ticket
{
public:
    //! Конструктор по умолчанию.
    Ticket();
    //! Деструктор.
    ~Ticket();
    //! Возвращает номер билета.
    const int &getNumber() const;
    //! Устанавливает номер билета.
    void setNumber(const int &number);
    //! Возвращает номер рейса.
    const int &getFlightNumber() const;
    //! Устанавливает номер рейса.
    void setFlightNumber(const int &flightNumber);
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
    int mNumber;
    //! Номер рейса
    int mFlightNumber;
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
