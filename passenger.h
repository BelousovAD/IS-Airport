#ifndef PASSENGER_H
#define PASSENGER_H

#include "user.h"

#include <QSet>

class Passenger:public User
{
public:
    //! Конструктор по умолчанию.
    Passenger();
    //! Деструктор.
    ~Passenger();
    //! Вставляет номер билета в set.
    void add(int number);
    //! Удаляет номер билета из set.
    void del(int number);
    //! Сохраняет пользователя в поток ost.
    void save(QDataStream &ost) const;
    //! Загружает пользователя из потока ist.
    void load(QDataStream &ist);
private:
    //! Внутренний контейнер для хранения номеров билетов.
    QSet<int> mTickets;
};

#endif // PASSENGER_H
