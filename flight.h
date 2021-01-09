#ifndef FLIGHT_H
#define FLIGHT_H

#include <QString>
#include <QTime>

class Flight
{
public:
    //! Конструктор по умолчанию
    Flight();
    //! Создаёт объект Flight с параметрами.
    Flight(qint32 number, QString departurePoint, QString arrivalPoint,
           QTime departureTime, QTime arrivalTime, QString mark,
           qint32 numberSeats, QVector<qint32> ticketNumbers);
    //! Возвращает номер рейса.
    const qint32 &getNumber() const;
    //! Устанавливает номер рейса.
    void setNumber(const qint32 &number);
    //! Возвращает пункт отправления.
    const QString &getDeparturePoint() const;
    //! Устанавливает пункт отправления.
    void setDeparturePoint(const QString &departurePoint);
    //! Возвращает пункт назначения.
    const QString &getArrivalPoint() const;
    //! Устанавливает пункт назначения.
    void setArrivalPoint(const QString &arrivalPoint);
    //! Возвращает время вылета.
    const QTime &getDepartureTime() const;
    //! Устанавливает время вылета.
    void setDepartureTime(const QTime &departureTime);
    //! Возвращает время прибытия.
    const QTime &getArrivalTime() const;
    //! Устанавливает время прибытия.
    void setArrivalTime(const QTime &arrivalTime);
    //! Возвращает марка самолёта.
    const QString &getMark() const;
    //! Устанавливает марка самолёта.
    void setMark(const QString &mark);
    //! Возвращает число мест.
    const qint32 &getNumberSeats() const;
    //! Устанавливает число мест.
    void setNumberSeats(const qint32 &numberSeats);
    //! Возвращает cписок номеров билетов.
    const qint32 &getTicketNumbers() const;
    //! Устанавливает cписок номеров билетов.
    void setTicketNumbers(const qint32 &ticketNumbers);
    //! Сохраняет рейс в поток ost.
    void save(QDataStream &ost) const;
    //! Загружает рейс из потока ist.
    void load(QDataStream &ist);
private:
    //! Номер рейса
    qint32 mNumber;
    //! Пункт отправления
    QString mDeparturePoint;
    //! Пункт назначения
    QString mArrivalPoint;
    //! Время вылета
    QTime mDepartureTime;
    //! Время прибытия
    QTime mArrivalTime;
    //! Марка самолёта
    QString mMark;
    //! Число мест
    qint32 mNumberSeats;
    //! Список номеров билетов
    QVector<qint32> mTicketNumbers;
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
