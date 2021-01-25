#include "menuadmindialog.h"
#include "ui_menuadmindialog.h"
#include "registrationdialog.h"

#include <QMessageBox>

MenuAdminDialog::MenuAdminDialog(QWidget *parent, User *mCurUser, UsersBook *mUsersbook) :
    QDialog(parent),
    ui(new Ui::MenuAdminDialog)
{
    ui->setupUi(this);
    this->mCurUser = mCurUser;
    this->mUsersbook = mUsersbook;
    // Конструирование таблицы
    for (int i = 0; i < (*mUsersbook).size(); ++i)
    {
        User *user = (*mUsersbook)[i];
        QTableWidgetItem *item_login = new QTableWidgetItem(user->getLogin());
        QTableWidgetItem *item_root;
        if (dynamic_cast<Admin*>(user) != nullptr)
        {
            item_root = new QTableWidgetItem("Администратор");
        }
        else if (dynamic_cast<Cashier*>(user) != nullptr)
        {
            item_root = new QTableWidgetItem("Кассир");
        }
        else
        {
            item_root = new QTableWidgetItem("Пассажир");
        }
        ui->usersTableWidget->insertRow(i);
        ui->usersTableWidget->setItem(i, 0, item_login);
        ui->usersTableWidget->setItem(i, 1, item_root);
    }
}

MenuAdminDialog::~MenuAdminDialog()
{
    delete ui;
}

void MenuAdminDialog::on_addButton_clicked()
{
    RegistrationDialog registrationdialog(this, mUsersbook);
    if (registrationdialog.exec() == QDialog::Accepted)
    {
        int row = ui->usersTableWidget->rowCount();
        User *user = (*mUsersbook)[row];
        QTableWidgetItem *item_login = new QTableWidgetItem(user->getLogin());
        QTableWidgetItem *item_root = new QTableWidgetItem("Пассажир");
        ui->usersTableWidget->insertRow(row);
        ui->usersTableWidget->setItem(row, 0, item_login);
        ui->usersTableWidget->setItem(row, 1, item_root);
    }
}

void MenuAdminDialog::on_delButton_clicked()
{
    int currentRow = ui->usersTableWidget->currentRow();
    if (currentRow != -1) {
        (*mUsersbook).erase(currentRow);
        ui->usersTableWidget->removeRow(currentRow);
    }
    else {
        QMessageBox::warning(this, windowTitle(), "Не выбран ни один пользователь");
    }
}

void MenuAdminDialog::on_riseButton_clicked()
{
    int currentRow = ui->usersTableWidget->currentRow();
    User *user = (*mUsersbook)[currentRow];
    if (currentRow != -1) {
        if (dynamic_cast<Admin*>(user) != nullptr)
        {
            QMessageBox::warning(this, windowTitle(), "Невозможно повысить пользователя");
        }
        else if (dynamic_cast<Cashier*>(user))
        {
            int row = ui->usersTableWidget->rowCount();
            Admin *admin = new Admin;
            admin->setDateLogin(user->getDateLogin());
            admin->setLogin(user->getLogin());
            admin->setMidname(user->getMidname());
            admin->setName(user->getName());
            admin->setPassportNumber(user->getPassportNumber());
            admin->setPassportSerial(user->getPassportSerial());
            admin->setPassword(user->getPassword());
            admin->setSurname(user->getSurname());
            (*mUsersbook).insert(*admin);
            (*mUsersbook).erase(currentRow);
            ui->usersTableWidget->removeRow(currentRow);
            QTableWidgetItem *item_login = new QTableWidgetItem(admin->getLogin());
            QTableWidgetItem *item_root = new QTableWidgetItem("Администратор");
            ui->usersTableWidget->insertRow(row);
            ui->usersTableWidget->setItem(row, 0, item_login);
            ui->usersTableWidget->setItem(row, 1, item_root);

        }
        else if (dynamic_cast<Passenger*>(user))
        {
            int row = ui->usersTableWidget->rowCount();
            Cashier *cashier = new Cashier;
            cashier->setDateLogin(user->getDateLogin());
            cashier->setLogin(user->getLogin());
            cashier->setMidname(user->getMidname());
            cashier->setName(user->getName());
            cashier->setPassportNumber(user->getPassportNumber());
            cashier->setPassportSerial(user->getPassportSerial());
            cashier->setPassword(user->getPassword());
            cashier->setSurname(user->getSurname());
            (*mUsersbook).insert(*cashier);
            (*mUsersbook).erase(currentRow);
            ui->usersTableWidget->removeRow(currentRow);
            QTableWidgetItem *item_login = new QTableWidgetItem(cashier->getLogin());
            QTableWidgetItem *item_root = new QTableWidgetItem("Кассир");
            ui->usersTableWidget->insertRow(row);
            ui->usersTableWidget->setItem(row, 0, item_login);
            ui->usersTableWidget->setItem(row, 1, item_root);
        }
    }
    else {
        QMessageBox::warning(this, windowTitle(), "Не выбран ни один пользователь");
    }
}
