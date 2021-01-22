#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent, User *mCurUser, UsersBook *mUsersbook,
                       FlightsBook *mFlightsbook, TicketsBook *mTicketsbook) :
    QWidget(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    this->mCurUser = mCurUser;
    this->mUsersbook = mUsersbook;
    this->mFlightsbook = mFlightsbook;
    this->mTicketsbook = mTicketsbook;
}

MenuWindow::~MenuWindow()
{
    delete ui;
}
