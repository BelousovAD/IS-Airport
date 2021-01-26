#include "authorisationdialog.h"
#include "ui_authorisationdialog.h"

#include <QFile>

AuthorisationDialog::AuthorisationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorisationDialog)
{
    mUsersbook = new UsersBook;
    mFlightsbook = new FlightsBook;
    mTicketsbook = new TicketsBook;
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
    mUsersbook->load(istadmin, istcashier, istpassenger);
    istflight >> *mFlightsbook;
    istticket >> *mTicketsbook;
    // Закрываем файлы
    fileAdmins.close();
    fileCashiers.close();
    filePassengers.close();
    fileFlights.close();
    fileTickets.close();
    ui->setupUi(this);
}

AuthorisationDialog::~AuthorisationDialog()
{
    QFile fileAdmins("admins.bin");
    QFile fileCashiers("cashiers.bin");
    QFile filePassengers("users.bin");
    QFile fileFlights("flights.bin");
    QFile fileTickets("tickets.bin");
    // Отчищаем файлы
    fileAdmins.remove();
    fileCashiers.remove();
    filePassengers.remove();
    fileFlights.remove();
    fileTickets.remove();
    // Открываем файлы только для перезаписи
    fileAdmins.open(QIODevice::WriteOnly);
    fileCashiers.open(QIODevice::WriteOnly);
    filePassengers.open(QIODevice::WriteOnly);
    fileFlights.open(QIODevice::WriteOnly);
    fileTickets.open(QIODevice::WriteOnly);
    // Привязываем к файлам поток, позволяющий записывать объекты Qt
    QDataStream ostadmin(&fileAdmins);
    QDataStream ostcashier(&fileCashiers);
    QDataStream ostpassenger(&filePassengers);
    QDataStream ostflight(&fileFlights);
    QDataStream ostticket(&fileTickets);
    // Загружаем данные в файлы
    mUsersbook->save(ostadmin, ostcashier, ostpassenger);
    ostflight << *mFlightsbook;
    ostticket << *mTicketsbook;
    // Закрываем файлы
    fileAdmins.close();
    fileCashiers.close();
    filePassengers.close();
    fileFlights.close();
    fileTickets.close();
    delete ui;
}

void AuthorisationDialog::on_registrationButton_clicked()
{
    mRegistrationDialog = new RegistrationDialog(this, mUsersbook);
    this->hide();
    connect(mRegistrationDialog, SIGNAL(accepted()), this, SLOT(slotShow()));
    connect(mRegistrationDialog, SIGNAL(rejected()), this, SLOT(slotShow()));
    mRegistrationDialog->open();
}

void AuthorisationDialog::on_authorisationButton_clicked()
{
    //if ()
    for (int i = 0; i < (*mUsersbook).size(); ++i)
    {
        if ((*mUsersbook)[i]->getLogin() == ui->loginLine->text()
                && (*mUsersbook)[i]->getPassword() == ui->passwordLine->text())
        {
            mCurUser = (*mUsersbook)[i];
            mCurUser->setDateLogin(QDate::currentDate());
            mMainDialog = new MainDialog(this, mUsersbook, mFlightsbook, mTicketsbook, mCurUser);
            this->hide();
            connect(mMainDialog, SIGNAL(accepted()), this, SLOT(slotShow()));
            connect(mMainDialog, SIGNAL(rejected()), this, SLOT(slotShow()));
            mMainDialog->open();
            return;
        }
    }
    ui->errorLabel->setText(tr("Пользователь с такими данными не зарегистрирован"));
}

void AuthorisationDialog::slotShow()
{
    this->show();
}

