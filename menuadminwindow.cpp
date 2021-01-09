#include "menuadminwindow.h"
#include "ui_menuadminwindow.h"

MenuAdminWindow::MenuAdminWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuAdminWindow)
{
    ui->setupUi(this);
}

MenuAdminWindow::~MenuAdminWindow()
{
    delete ui;
}
