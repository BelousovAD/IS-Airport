#include "menudialog.h"
#include "ui_menudialog.h"
#include "accountdialog.h"

MenuDialog::MenuDialog(QWidget *parent, User *mCurUser, UsersBook *mUsersbook,
                       FlightsBook *mFlightsbook, TicketsBook *mTicketsbook) :
    QDialog(parent),
    ui(new Ui::MenuDialog)
{
    ui->setupUi(this);
    this->mCurUser = mCurUser;
    this->mUsersbook = mUsersbook;
    this->mFlightsbook = mFlightsbook;
    this->mTicketsbook = mTicketsbook;
}

MenuDialog::~MenuDialog()
{
    delete ui;
}

void MenuDialog::on_accountButton_clicked()
{
    AccountDialog accountdialog(this, mCurUser, mUsersbook);
    accountdialog.setModal(true);
    this->hide();
    accountdialog.exec();
    this->show();
}
