#include "menucashierwindow.h"
#include "ui_menucashierwindow.h"

MenuCashierWindow::MenuCashierWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuCashierWindow)
{
    ui->setupUi(this);
}

MenuCashierWindow::~MenuCashierWindow()
{
    delete ui;
}
