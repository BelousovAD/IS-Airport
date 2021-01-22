#ifndef BOOK_H
#define BOOK_H

#include <QDataStream>

#include "user.h"
#include "flight.h"
#include "ticket.h"

template<class T>
class Book
{
public:
    //! Конструктор по умолчанию.
    Book();
    //! Определяет размер коллекции.
    int size() const;
    //! Перегрузка оператора.
    const T &operator[](int idx) const;
    //! Сохраняет книжку в поток ost.
    void save(QDataStream &ost) const;
    //! Загружает книжку из потока ist.
    void load(QDataStream &ist);
    //! Вставляет элемент в книжку.
    void insert(T &element);
    //! Удаляет запись с индексом idx из книжки.
    void erase(int idx);
    //! Обновляет данные элемента.
    void edit(int index, T &element);
protected:
    QVector<T*> mCollection;
};

//! Реализация оператора << для вывода Notebook в QDataStream.
template<class T>
inline QDataStream &operator<<(QDataStream &ost, const Book<T> &book)
{
    book.save(ost);
    return ost;
}

//! Реализация оператора >> для ввода Notebook из QDataStream.
template<class T>
inline QDataStream &operator>>(QDataStream &ist, Book<T> &book)
{
    book.load(ist);
    return ist;
}

template class Book<User>;
template class Book<Flight>;
template class Book<Ticket>;
#endif // BOOK_H
