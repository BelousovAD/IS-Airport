#include "authorisationwindow.h"
#include "mainwindow.h"
#include "registrationwindow.h"
#include "ui_authorisationwindow.h"

AuthorisationWindow::AuthorisationWindow(QWidget *parent, UsersBook *mUsersbook,
                                         FlightsBook *mFlightsbook, TicketsBook *mTicketsbook,
                                         User *mCurUser) :
    QWidget(parent),
    ui(new Ui::AuthorisationWindow)
{
    ui->setupUi(this);
    this->mUsersbook = mUsersbook;
    this->mFlightsbook = mFlightsbook;
    this->mTicketsbook = mTicketsbook;
    this->mCurUser = mCurUser;
}

AuthorisationWindow::~AuthorisationWindow()
{
    delete ui;
}

void AuthorisationWindow::on_registrationButton_clicked()
{
    RegistrationWindow r(this, mUsersbook);
    this->hide();
}

void AuthorisationWindow::on_authorisationButton_clicked()
{
    //if ()
    for (int i = 0; i < (*mUsersbook).size(); ++i)
    {
        if ((*mUsersbook).getUser(i).getLogin() == ui->loginLine->text()
                && (*mUsersbook).getUser(i).getPassword() == ui->passwordLine->text())
        {
            *mCurUser = (*mUsersbook).getUser(i);
            MainWindow w(nullptr, mCurUser, mUsersbook, mFlightsbook,mTicketsbook);
            w.show();
            this->destroy();
        }
    }
    ui->errorLabel->setText(tr("Пользователь с такими данными не зарегистрирован"));
}
