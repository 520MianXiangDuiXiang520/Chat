#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "user.h"
#include "utils.h"
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
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
