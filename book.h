#ifndef BOOK_H
#define BOOK_H

#include <QAbstractTableModel>

class Book : public QAbstractTableModel
{
public:
    //! Конструктор по умолчанию.
    Book();
    //! Определяет размер коллекции.
    int size() const;
    //! Определяет количество строк в модели.
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    //! Определяет количество столбцов в модели.
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    //! Возвращает данные указанной роли для указанного элемента модели.
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    //! Возвращает данные указанной роли для указанного заголовка модели.
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    //! Сохраняет книжку в поток ost.
    void save(QDataStream &ost) const;
    //! Загружает книжку из потока ist. Возвращает количество загруженных заметок.
    int load(QDataStream &ist);
    //! Удаляет запись с индексом idx из книжки.
    void erase(int idx);
};

//! Реализация оператора << для вывода Notebook в QDataStream.
inline QDataStream &operator<<(QDataStream &ost, const Book &book)
{
    book.save(ost);
    return ost;
}

//! Реализация оператора >> для ввода Notebook из QDataStream.
inline QDataStream &operator>>(QDataStream &ist, Book &book)
{
    book.load(ist);
    return ist;
}

#endif // BOOK_H
