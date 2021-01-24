#ifndef MENUDIALOG_H
#define MENUDIALOG_H

#include "flightsbook.h"
#include "ticketsbook.h"
#include "usersbook.h"

#include <QDialog>

namespace Ui {
class MenuDialog;
}

class MenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuDialog(QWidget *parent = nullptr, User *mCurUser = nullptr, UsersBook *mUsersbook = nullptr,
                        FlightsBook *mFlightsbook = nullptr, TicketsBook *mTicketsbook = nullptr);
    ~MenuDialog();

private slots:
    void on_accountButton_clicked();

private:
    Ui::MenuDialog *ui;
    UsersBook *mUsersbook;
    FlightsBook *mFlightsbook;
    TicketsBook *mTicketsbook;
    User *mCurUser;
};

#endif // MENUDIALOG_H
