#ifndef MENUADMINWINDOW_H
#define MENUADMINWINDOW_H

#include <QWidget>

namespace Ui {
class MenuAdminWindow;
}

class MenuAdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MenuAdminWindow(QWidget *parent = nullptr);
    ~MenuAdminWindow();

private:
    Ui::MenuAdminWindow *ui;
};

#endif // MENUADMINWINDOW_H
