#ifndef USER_H
#define USER_H
#include <iostream>
#include <QString>


class User
{
public:
    QString token;
    User(QString uid, QString username);
    QString getUID();
    void setUID(QString uid);
    QString getPSW();
    void setPSW(QString psw);
    QString getUsername();
    void setUsername(QString username);
    QString getAddr();
    void setAddr(QString addr);

private:
    QString UID;
    QString PSW;
    QString username;
    QString addr;
};

#endif // USER_H
