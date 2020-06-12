#include "regist.h"

Regist::Regist()
{

}

User* Regist::auth(QString name, QString psw, QString apsw)
{
    if(psw != apsw)
    {
        qDebug() << "两次密码不相同";
    }
    else
    {
        RegistMessage *rm = new RegistMessage ();
        QString localIP = utils::getLocalIP();
        QString serverIP = "192.168.1.7";
        char message[128] = {'*'};
        rm->setData(message, 2, localIP, serverIP, psw, name, apsw);
        qDebug() << "message" << message;
        int socket = utils::conn(serverIP);
        write(socket, message, strlen(message));
        qDebug() << "发完了";
        char result[128];
        int resultLen = read(socket, result, 128 - 1);
        if(resultLen <= 0)
            qDebug() << "未收到服务器响应";
        else
            qDebug() << result;

        close(socket);
        return nullptr;
    }

}
