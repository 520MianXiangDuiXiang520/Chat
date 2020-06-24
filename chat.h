#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include "user.h"

namespace Ui {
class Chat;
}

class Chat : public QMainWindow
{
    Q_OBJECT

public:
    User *user;
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();

private:
    Ui::Chat *ui;
};

#endif // CHAT_H
