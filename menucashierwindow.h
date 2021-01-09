#ifndef MENUCASHIERWINDOW_H
#define MENUCASHIERWINDOW_H

#include <QWidget>

namespace Ui {
class MenuCashierWindow;
}

class MenuCashierWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MenuCashierWindow(QWidget *parent = nullptr);
    ~MenuCashierWindow();

private:
    Ui::MenuCashierWindow *ui;
};

#endif // MENUCASHIERWINDOW_H
