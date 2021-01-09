#ifndef AUTHORISATIONWINDOW_H
#define AUTHORISATIONWINDOW_H

#include <QWidget>

namespace Ui {
class AuthorisationWindow;
}

class AuthorisationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AuthorisationWindow(QWidget *parent = nullptr);
    ~AuthorisationWindow();

private:
    Ui::AuthorisationWindow *ui;
};

#endif // AUTHORISATIONWINDOW_H
