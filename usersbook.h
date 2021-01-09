#ifndef USERSBOOK_H
#define USERSBOOK_H

#include "book.h"
#include "user.h"

class UsersBook : public Book
{
public:
    //! Конструктор по умолчанию
    UsersBook();
    //! Перегрузка оператора.
    const User &operator[](int idx) const;
    //! Вставляет пользователя в книжку.
    void insert(const User &user);
    //! Возвращает пользователя по индексу.
    const User &getUser(int index) const;
    //! Обновляет данные пользователя.
    void edit(QModelIndex index, User user);
private:
    //! Внутренний контейнер для хранения пользователей.
    QVector<User> mNotes;
};

#endif // USERSBOOK_H
