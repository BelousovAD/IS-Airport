#include "registrationwindow.h"
#include "ui_registrationwindow.h"

#include <QMessageBox>

RegistrationWindow::RegistrationWindow(QWidget *parent, UsersBook *mUsersbook) :
    QWidget(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    this->mUsersbook = mUsersbook;
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}


void RegistrationWindow::on_registrationButton_clicked()
{
    //if()
    if (ui->passwordLine->text() != ui->repeatPasswordLine->text())
    {
        ui->errorLabel->setText(tr("Пароль не совпадает с повтором пароля"));
        return;
    }
    User* user = new Passenger();
    user->setLogin(ui->loginLine->text());
    user->setPassword(ui->passwordLine->text());
    for (int i = 0; i < (*mUsersbook).size(); ++i)
    {
        if ((*mUsersbook)[i].getLogin() == ui->loginLine->text())
        {
            ui->errorLabel->setText(tr("Пользователь с такими данными уже зарегистрирован"));
            return;
        }
    }
    (*mUsersbook).insert(*user);
    QMessageBox successful;
    successful.setText(tr("Пользователь успешно зарегистрирован"));
    successful.exec();
    parentWidget()->show();
    this->destroy();
}

void RegistrationWindow::on_authorisationButton_clicked()
{
    parentWidget()->show();
    this->destroy();
}
