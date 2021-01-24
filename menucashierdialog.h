#ifndef MENUCASHIERDIALOG_H
#define MENUCASHIERDIALOG_H

#include <QDialog>

namespace Ui {
class MenuCashierDialog;
}

class MenuCashierDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuCashierDialog(QWidget *parent = nullptr);
    ~MenuCashierDialog();

private:
    Ui::MenuCashierDialog *ui;
};

#endif // MENUCASHIERDIALOG_H
