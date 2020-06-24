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

/**
 * 发送消息
 * @brief Dialog::on_pushButton_clicked
 */
void Dialog::on_pushButton_clicked()
{
    write(this->conn, "message", strlen("message"));
    qDebug() << "ok";
}
