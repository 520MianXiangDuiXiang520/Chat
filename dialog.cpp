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

void Dialog::setMessage(QString message)
{

    this->reply = this->reply + message + '\n';
    qDebug() << "setMessage:" << this->reply;
    this->ui->textBrowser->setText(this->reply);
}

/**
 * 发送消息
 * @brief Dialog::on_pushButton_clicked
 */
void Dialog::on_pushButton_clicked()
{

    DataMessage *dm = new DataMessage();
    char message[2048];
    dm->setData(message, 4, "1", "1", this->user->token, "hello world");
    write(this->conn, message, strlen(message));
    qDebug() << "ok: " << message;

}
