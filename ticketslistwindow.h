#ifndef TICKETSLISTWINDOW_H
#define TICKETSLISTWINDOW_H

#include <QWidget>

namespace Ui {
class TicketsListWindow;
}

class TicketsListWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TicketsListWindow(QWidget *parent = nullptr);
    ~TicketsListWindow();

private:
    Ui::TicketsListWindow *ui;
};

#endif // TICKETSLISTWINDOW_H
