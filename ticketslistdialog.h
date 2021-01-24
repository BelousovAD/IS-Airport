#ifndef TICKETSLISTDIALOG_H
#define TICKETSLISTDIALOG_H

#include <QDialog>

namespace Ui {
class TicketsListDialog;
}

class TicketsListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TicketsListDialog(QWidget *parent = nullptr);
    ~TicketsListDialog();

private:
    Ui::TicketsListDialog *ui;
};

#endif // TICKETSLISTDIALOG_H
