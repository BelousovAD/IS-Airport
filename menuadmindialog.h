#ifndef MENUADMINDIALOG_H
#define MENUADMINDIALOG_H

#include <QDialog>

namespace Ui {
class MenuAdminDialog;
}

class MenuAdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuAdminDialog(QWidget *parent = nullptr);
    ~MenuAdminDialog();

private:
    Ui::MenuAdminDialog *ui;
};

#endif // MENUADMINDIALOG_H
