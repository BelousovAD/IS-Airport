#ifndef AUTHORISATIONWINDOW_H
#define AUTHORISATIONWINDOW_H

#include "flightsbook.h"
#include "ticketsbook.h"
#include "usersbook.h"

#include <QWidget>

namespace Ui {
class AuthorisationWindow;
}

class AuthorisationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AuthorisationWindow(QWidget *parent = nullptr, UsersBook *mUsersbook = nullptr,
                                 FlightsBook *mFlightsbook = nullptr, TicketsBook *mTicketsbook = nullptr,
                                 User *mCurUser = nullptr);
    ~AuthorisationWindow();

private slots:
    void on_registrationButton_clicked();

    void on_authorisationButton_clicked();

private:
    Ui::AuthorisationWindow *ui;
    UsersBook *mUsersbook;
    FlightsBook *mFlightsbook;
    TicketsBook *mTicketsbook;
    User *mCurUser;
};

#endif // AUTHORISATIONWINDOW_H
