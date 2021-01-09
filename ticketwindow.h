#ifndef TICKETWINDOW_H
#define TICKETWINDOW_H

#include <QWidget>

namespace Ui {
class TicketWindow;
}

class TicketWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TicketWindow(QWidget *parent = nullptr);
    ~TicketWindow();

private:
    Ui::TicketWindow *ui;
};

#endif // TICKETWINDOW_H
