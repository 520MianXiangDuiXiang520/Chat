#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <unistd.h>
#include <arpa/inet.h>
#include "user.h"
#include "utils.h"
#include "datamessage.h"
#include <QDebug>
#include <sys/socket.h>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    User *user;
    int conn;
    void doListen();
private slots:
    void on_pushButton_clicked();
    void setMessage(QString  message);

signals:
    void showMessage(QString  message);

private:
    Ui::Dialog *ui;
    QString reply;
};

#endif // DIALOG_H
