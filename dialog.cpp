#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_textBrowser_textChanged()
{
    ui->textBrowser->setText(this->message);
}

void Dialog::setMessage(QString mes)
{
    this->message = mes;
}
