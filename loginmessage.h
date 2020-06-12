#ifndef BASEMESSAGE_H
#define BASEMESSAGE_H
#define MAX_LOGIN_MESSAGE 128
#include <QString>
#include <QDebug>
#include <iostream>
#include <string>


class LoginMessage
{
protected:
    void setType(char * message);
    void setWork(char * message, char workType);
    void setFrom(char * message, QString fromIP);
    void setTo(char * message, QString toIP);
    void setPSW(char * message, QString psw);
    void setUID(char * message, QString uid);
    void setSize(char *message);
    QString findString(char *message);
    static QString getLenMessage(char *message, int offset);
private:
    int size = 0;
    int len = 2;
    static void setLenMessage(char *message, QString data, int offset);
public:
    QString UID;
    QString Name;
    QString Token;
    LoginMessage();
    void setData(char * message, int workType, QString fromIP,
                 QString toIP, QString PSW, QString UID);
    //char *getMessage();
    //QString getMessage();
    static int getType(char *message);
    static int getWork(char *message);
    static QString getFrom(char *message);
    static QString getTo(char *message);
    static QString getPSW(char *message);
    static QString getUID(char *message);
    char findType(char *message);
    int findWork(char *message);
    void findData(char* message);

};

#endif // BASEMESSAGE_H
