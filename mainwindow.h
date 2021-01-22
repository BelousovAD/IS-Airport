#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "flightsbook.h"
#include "ticketsbook.h"
#include "usersbook.h"

#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, User *mCurUser = nullptr, UsersBook *mUsersbook = nullptr,
                        FlightsBook *mFlightsbook = nullptr, TicketsBook *mTicketsbook = nullptr);
    ~MainWindow();
    void setCurUser(const User &mCurUser);
    int &getCurUser() const;

private slots:
    void on_menuButton_clicked();

private:
    Ui::MainWindow *ui;
    User *mCurUser;
    UsersBook *mUsersbook;
    FlightsBook *mFlightsbook;
    TicketsBook *mTicketsbook;
};

#endif // MAINWINDOW_H
