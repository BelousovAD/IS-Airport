#include "menudialog.h"
#include "ui_menudialog.h"
#include "menuadmindialog.h"
#include "accountdialog.h"
#include "ticketslistdialog.h"

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
    if (dynamic_cast<Admin*>(mCurUser) == nullptr)
    {
        ui->adminButton->hide();
    }
    if (dynamic_cast<Passenger*>(mCurUser) == nullptr)
    {
        ui->ticketsButton->hide();
    }
}

MenuDialog::~MenuDialog()
{
    delete ui;
}

void MenuDialog::on_accountButton_clicked()
{
    AccountDialog accountdialog(this, mCurUser, mUsersbook);
    this->hide();
    accountdialog.exec();
    this->show();
}

void MenuDialog::on_ticketsButton_clicked()
{
    TicketsListDialog ticketslistdialog(this, mCurUser, mFlightsbook, mTicketsbook);
    this->hide();
    ticketslistdialog.exec();
    this->show();
}

void MenuDialog::on_adminButton_clicked()
{
    MenuAdminDialog menuadmindialog(this, mCurUser, mUsersbook);
    this->hide();
    menuadmindialog.exec();
    this->show();
}
