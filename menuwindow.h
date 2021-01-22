#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "flightsbook.h"
#include "ticketsbook.h"
#include "usersbook.h"

#include <QWidget>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr, User *mCurUser = nullptr, UsersBook *mUsersbook = nullptr,
                        FlightsBook *mFlightsbook = nullptr, TicketsBook *mTicketsbook = nullptr);
    ~MenuWindow();

private:
    Ui::MenuWindow *ui;
    UsersBook *mUsersbook;
    FlightsBook *mFlightsbook;
    TicketsBook *mTicketsbook;
    User *mCurUser;
};

#endif // MENUWINDOW_H
