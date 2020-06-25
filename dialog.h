#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <unistd.h>
#include <arpa/inet.h>
#include "user.h"
#include "utils.h"
#include "datamessage.h"
#include <QDebug>

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
    void setMessage(QString  message);
private slots:
    void on_pushButton_clicked();


private:
    Ui::Dialog *ui;
    QString reply;
};

#endif // DIALOG_H
