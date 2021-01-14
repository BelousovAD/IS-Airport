#include "authorisationwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, User *mCurUser,
                       UsersBook *mUsersbook, FlightsBook *mFlightsbook,
                       TicketsBook *mTicketsbook) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mCurUser = mCurUser;
    this->mUsersbook = mUsersbook;
    this->mFlightsbook = mFlightsbook;
    this->mTicketsbook = mTicketsbook;
}

MainWindow::~MainWindow()
{
    delete ui;
}
