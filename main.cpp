#include "authorisationdialog.h"

#include <QApplication>
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
        // Открываем файл только для записи
        fileAdmins.open(QIODevice::Append);
        // Привязываем к файлу поток, позволяющий выводить объекты Qt
        QDataStream ost(&fileAdmins);
        // Выводим первого администратора в файл
        ost << firstAdmin;
        fileAdmins.close();
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
    AuthorisationDialog window(nullptr, &usersbook, &flightsbook, &ticketsbook);
    window.show();
    return a.exec();
}
