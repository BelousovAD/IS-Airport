#ifndef BUYTICKETDIALOG_H
#define BUYTICKETDIALOG_H

#include <QDialog>
#include <QValidator>

namespace Ui {
class BuyTicketDialog;
}

class BuyTicketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BuyTicketDialog(QWidget *parent = nullptr);
    ~BuyTicketDialog();

private:
    Ui::BuyTicketDialog *ui;
};

#endif // BUYTICKETDIALOG_H
