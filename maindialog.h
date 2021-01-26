#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include "flightsbook.h"
#include "ticketsbook.h"
#include "usersbook.h"

#include "addflightdialog.h"
#include "menucashierdialog.h"
#include "menudialog.h"

#include <QDialog>

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr, UsersBook *mUsersbook = nullptr,
                        FlightsBook *mFlightsbook = nullptr, TicketsBook *mTicketsbook = nullptr,
                        User *mCurUser = nullptr);
    ~MainDialog();

private slots:
    void on_menuButton_clicked();

private:
    Ui::MainDialog *ui;
    User *mCurUser;
    UsersBook *mUsersbook;
    FlightsBook *mFlightsbook;
    TicketsBook *mTicketsbook;
    AddFlightDialog *mAddFlightDialog;
    MenuCashierDialog *mMenuCashierDialog;
    MenuDialog *mMenuDialog;
};

#endif // MAINDIALOG_H
