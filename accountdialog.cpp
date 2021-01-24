#include "accountdialog.h"
#include "ui_accountdialog.h"

AccountDialog::AccountDialog(QWidget *parent, User *mCurUser, UsersBook *mUsersbook) :
    QDialog(parent),
    ui(new Ui::AccountDialog)
{
    ui->setupUi(this);
    this->mCurUser = mCurUser;
    this->mUsersbook = mUsersbook;
    ui->loginLine->setText(mCurUser->getLogin());
    ui->midnameLine->setText(mCurUser->getMidname());
    ui->nameLine->setText(mCurUser->getName());
    ui->passportNumberLine->setText(QString::number(mCurUser->getPassportNumber()));
    ui->passportSerialLine->setText(QString::number(mCurUser->getPassportSerial()));
    ui->surnameLine->setText(mCurUser->getSurname());
    ui->passwordLine->setText(mCurUser->getPassword());
    if (dynamic_cast<Admin*>(mCurUser) != nullptr)
    {
        ui->rootLine->setText("Администратор");
    }
    else if (dynamic_cast<Cashier*>(mCurUser) != nullptr)
    {
        ui->rootLine->setText("Кассир");
    }
    else
    {
        ui->rootLine->setText("Пассажир");
    }
}

AccountDialog::~AccountDialog()
{
    delete ui;
}

void AccountDialog::on_OKButton_clicked()
{
    //if()
    for (int i = 0; i < mUsersbook->size(); ++i)
    {
        if (ui->loginLine->text() == (*mUsersbook)[i]->getLogin() && mCurUser != (*mUsersbook)[i])
        {
            ui->errorLabel->setText("Пользователь с таким логином уже существует");
            return;
        }
    }
    mCurUser->setLogin(ui->loginLine->text());
    mCurUser->setMidname(ui->midnameLine->text());
    mCurUser->setName(ui->nameLine->text());
    mCurUser->setPassportNumber(ui->passportNumberLine->text().toInt());
    mCurUser->setPassportSerial(ui->passportSerialLine->text().toUInt());
    mCurUser->setPassword(ui->passwordLine->text());
    mCurUser->setSurname(ui->surnameLine->text());
    QDialog::accept();
}
