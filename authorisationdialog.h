#ifndef AUTHORISATIONDIALOG_H
#define AUTHORISATIONDIALOG_H

#include "flightsbook.h"
#include "ticketsbook.h"
#include "usersbook.h"

#include <QDialog>

namespace Ui {
class AuthorisationDialog;
}

class AuthorisationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorisationDialog(QWidget *parent = nullptr);
    ~AuthorisationDialog();

private slots:
    void on_registrationButton_clicked();

    void on_authorisationButton_clicked();

private:
    Ui::AuthorisationDialog *ui;
    UsersBook *mUsersbook;
    FlightsBook *mFlightsbook;
    TicketsBook *mTicketsbook;
    User *mCurUser;
};

#endif // AUTHORISATIONDIALOG_H
