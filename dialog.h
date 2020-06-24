#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "user.h"
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
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
