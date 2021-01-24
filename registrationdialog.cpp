#include "registrationdialog.h"
#include "ui_registrationdialog.h"

#include <QMessageBox>

RegistrationDialog::RegistrationDialog(QWidget *parent, UsersBook *mUsersbook) :
    QDialog(parent),
    ui(new Ui::RegistrationDialog)
{
    ui->setupUi(this);
    this->mUsersbook = mUsersbook;
}

RegistrationDialog::~RegistrationDialog()
{
    delete ui;
}

void RegistrationDialog::on_registrationButton_clicked()
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
        if ((*mUsersbook)[i]->getLogin() == ui->loginLine->text())
        {
            ui->errorLabel->setText(tr("Пользователь с такими данными уже зарегистрирован"));
            return;
        }
    }
    (*mUsersbook).insert(*user);
    QMessageBox successful;
    successful.setText(tr("Пользователь успешно зарегистрирован"));
    successful.exec();
    QDialog::accept();
}

void RegistrationDialog::on_authorisationButton_clicked()
{
    QDialog::close();
}
