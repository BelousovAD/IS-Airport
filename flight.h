#ifndef FLIGHT_H
#define FLIGHT_H

#include <QDataStream>
#include <QString>
#include <QDateTime>

class Flight
{
public:
    //! Конструктор по умолчанию
    Flight();
    //! Деструктор.
    ~Flight();
    //! Возвращает номер рейса.
    const int &getNumber() const;
    //! Устанавливает номер рейса.
    void setNumber(const int &number);
    //! Возвращает пункт отправления.
    const QString &getDeparturePoint() const;
    //! Устанавливает пункт отправления.
    void setDeparturePoint(const QString &departurePoint);
    //! Возвращает пункт назначения.
    const QString &getArrivalPoint() const;
    //! Устанавливает пункт назначения.
    void setArrivalPoint(const QString &arrivalPoint);
    //! Возвращает дату и время вылета.
    const QDateTime &getDepartureDateTime() const;
    //! Устанавливает дату и время вылета.
    void setDepartureDateTime(const QDateTime &departureDateTime);
    //! Возвращает дату и время прибытия.
    const QDateTime &getArrivalDateTime() const;
    //! Устанавливает дату и время прибытия.
    void setArrivalDateTime(const QDateTime &arrivalDateTime);
    //! Возвращает марка самолёта.
    const QString &getMark() const;
    //! Устанавливает марка самолёта.
    void setMark(const QString &mark);
    //! Возвращает число мест.
    const int &getNumberSeats() const;
    //! Устанавливает число мест.
    void setNumberSeats(const int &numberSeats);
    //! Возвращает cписок номеров билетов.
    const QVector<int> &getTicketNumbers() const;
    //! Устанавливает cписок номеров билетов.
    void setTicketNumbers(const QVector<int> &ticketNumbers);
    //! Сохраняет рейс в поток ost.
    void save(QDataStream &ost) const;
    //! Загружает рейс из потока ist.
    void load(QDataStream &ist);
private:
    //! Номер рейса
    int mNumber;
    //! Пункт отправления
    QString mDeparturePoint;
    //! Пункт назначения
    QString mArrivalPoint;
    //! Время вылета
    QDateTime mDepartureDateTime;
    //! Время прибытия
    QDateTime mArrivalDateTime;
    //! Марка самолёта
    QString mMark;
    //! Число мест
    int mNumberSeats;
    //! Список номеров билетов
    QVector<int> mTicketNumbers;
};

//! Реализация оператора << для вывода Flight в QDataStream.
inline QDataStream &operator<<(QDataStream &ost, const Flight &flight)
{
    flight.save(ost);
    return ost;
}

//! Реализация оператора >> для вввода Flight из QDataStream.
inline QDataStream &operator>>(QDataStream &ist, Flight &flight)
{
    flight.load(ist);
    return ist;
}

#endif // FLIGHT_H
