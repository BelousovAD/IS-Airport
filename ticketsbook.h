#ifndef TICKETSBOOK_H
#define TICKETSBOOK_H

#include "book.h"
#include "ticket.h"

class TicketsBook : public Book
{
public:
    //! Конструктор по умолчанию.
    TicketsBook();
    //! Перегрузка оператора.
    const Ticket &operator[](int idx) const;
    //! Вставляет билет в книжку.
    void insert(const Ticket &user);
    //! Возвращает билет по индексу.
    const Ticket &getTicket(int index) const;
    //! Обновляет данные билета.
    void edit(QModelIndex index, Ticket user);
private:
    //! Внутренний контейнер для хранения билетов.
    QVector<Ticket> mNotes;
};

#endif // TICKETSBOOK_H
