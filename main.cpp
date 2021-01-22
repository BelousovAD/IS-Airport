#include "authorisationwindow.h"

#include <QApplication>
#include <QSaveFile>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UsersBook usersbook;
    FlightsBook flightsbook;
    TicketsBook ticketsbook;
    QFile fileAdmins("admins.bin");
    QFile fileCashiers("cashiers.bin");
    QFile filePassengers("users.bin");
    QFile fileFlights("flights.bin");
    QFile fileTickets("tickets.bin");
    if (!fileAdmins.exists())
    {
        Admin firstAdmin;
        firstAdmin.setLogin("admin");
        firstAdmin.setPassword("12345");
        /*
         * Создаём объект outf, связанный с файлом fileName.
         * QSaveFile обеспечивает безопасное сохранение (через промежуточный
         * временный файл), чтобы избежать потери данных в случае нештатного
         * завершения операции сохранения. Само сохранение происходит при вызове
         * метода commit().
         */
        QSaveFile outf("admins.bin");
        // Открываем файл только для записи
        outf.open(QIODevice::WriteOnly);
        // Привязываем к файлу поток, позволяющий выводить объекты Qt
        QDataStream ost(&outf);
        // Выводим первого администратора в файл
        ost << firstAdmin;
        // Запускаем сохранение
        outf.commit();
    }
    // Открываем файлы только для чтения
    fileAdmins.open(QIODevice::ReadOnly);
    fileCashiers.open(QIODevice::ReadOnly);
    filePassengers.open(QIODevice::ReadOnly);
    fileFlights.open(QIODevice::ReadOnly);
    fileTickets.open(QIODevice::ReadOnly);
    // Привязываем к файлам поток, позволяющий считывать объекты Qt
    QDataStream istadmin(&fileAdmins);
    QDataStream istcashier(&fileCashiers);
    QDataStream istpassenger(&filePassengers);
    QDataStream istflight(&fileFlights);
    QDataStream istticket(&fileTickets);
    // Загружаем данные из файлов
    usersbook.load(istadmin, istcashier, istpassenger);
    istflight >> flightsbook;
    istticket >> ticketsbook;
    AuthorisationWindow w(nullptr, &usersbook, &flightsbook, &ticketsbook);
    w.show();
    return a.exec();
}
