#include "authorisationwindow.h"
#include "registrationwindow.h"
#include "ui_authorisationwindow.h"

AuthorisationWindow::AuthorisationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthorisationWindow)
{
    ui->setupUi(this);
}

AuthorisationWindow::~AuthorisationWindow()
{
    delete ui;
}

void AuthorisationWindow::on_registrationButton_clicked()
{
    RegistrationWindow r(this);
    this->hide();
}

void AuthorisationWindow::on_authorisationButton_clicked()
{

}
