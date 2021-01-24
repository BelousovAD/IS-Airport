#include "authorisationdialog.h"
#include "ui_authorisationdialog.h"
#include "registrationdialog.h"
#include "maindialog.h"

AuthorisationDialog::AuthorisationDialog(QWidget *parent, UsersBook *mUsersbook,
                                         FlightsBook *mFlightsbook, TicketsBook *mTicketsbook) :
    QDialog(parent),
    ui(new Ui::AuthorisationDialog)
{
    ui->setupUi(this);
    this->mUsersbook = mUsersbook;
    this->mFlightsbook = mFlightsbook;
    this->mTicketsbook = mTicketsbook;
}

AuthorisationDialog::~AuthorisationDialog()
{

    delete ui;
}

void AuthorisationDialog::on_registrationButton_clicked()
{
    RegistrationDialog signUpDialog(this, mUsersbook);
    signUpDialog.setModal(true);
    this->hide();
    signUpDialog.exec();
    this->show();
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
            MainDialog window(this, mUsersbook, mFlightsbook, mTicketsbook, mCurUser);
            this->hide();
            window.exec();
            this->show();
        }
    }
    ui->errorLabel->setText(tr("Пользователь с такими данными не зарегистрирован"));
}
