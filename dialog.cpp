#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    if(fork() == 0)
    {
        qDebug() << "紫荆城";
        this->doListen();
    }
    else
    {
        ui->setupUi(this);
    }

}

Dialog::~Dialog()
{
    qDebug() << "Bye ~";
    delete ui;
}

void Dialog::doListen()
{
    connect(this, SIGNAL(showMessage(QString)), this, SLOT(setMessage(QString)));
    int clnt_sock;
    int serv_sock;
    serv_sock = utils::conn();
    while (1)
    {
        clnt_sock = utils::getClientSocket(serv_sock);
        if (clnt_sock == -1)
            continue;
        else
            puts("new client connected...");
        char result[2048];
        int resultLen = read(clnt_sock, result, 2048 - 1);
        if (resultLen > 0)
        {
            emit this->showMessage("hahahah");
            qDebug() << "result: " << result;
        }
        else
        {
            qDebug() << "no response!!";
        }
    }
}

void Dialog::setMessage(QString message)
{
    this->reply = this->reply + message + '\n';
    qDebug() << "setMessage:" << this->reply;
//    ui->replyBrowser->setHtml("<h1>ahhaha</h1>");
//    ui->sendBrowser->setHtml("<h1>1111</hhh>");
    qDebug() << "setMessssage:" << this->reply;
}

/**
 * 发送消息
 * @brief Dialog::on_pushButton_clicked
 */
void Dialog::on_pushButton_clicked()
{
//    ui->sendBrowser->setHtml("<h1>button</hhh>");
//    ui->replyBrowser->setHtml("<h1>button</h1>");
    DataMessage *dm = new DataMessage();
    char message[2048];
    dm->setData(message, 4, "1", "1", this->user->token, "hello world");
    write(this->conn, message, strlen(message));
    qDebug() << "ok: " << message;

}
