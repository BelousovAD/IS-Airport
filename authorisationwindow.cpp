#include "authorisationwindow.h"
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
