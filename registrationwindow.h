#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include "usersbook.h"

#include <QWidget>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr, UsersBook *mUsersbook = nullptr);
    ~RegistrationWindow();

private slots:
    void on_registrationButton_clicked();

    void on_authorisationButton_clicked();

private:
    Ui::RegistrationWindow *ui;
    UsersBook *mUsersbook;
};

#endif // REGISTRATIONWINDOW_H
