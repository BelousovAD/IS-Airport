#ifndef FLIGHTSBOOK_H
#define FLIGHTSBOOK_H

#include "book.h"
#include "flight.h"

class FlightsBook : public Book<Flight>
{
public:
    //! Конструктор по умолчанию
    FlightsBook();
    //! Перегрузка оператора.
    const Flight &operator[](int idx) const;
    //! Вставляет рейс в книжку.
    void insert(const Flight &user);
    //! Возвращает рейс по индексу.
    const Flight &getFlight(int index) const;
    //! Обновляет данные рейса.
    void edit(QModelIndex index, Flight user);
private:
    //! Внутренний контейнер для хранения рейсов.
    QVector<Flight> mFlights;
};

#endif // FLIGHTSBOOK_H
