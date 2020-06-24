#include "regist.h"

Regist::Regist()
{

}

User* Regist::auth(QString name, QString psw, QString apsw)
{
    if(name.length() <= 0 || psw.length() <= 0 || apsw.length() <= 0)
        return nullptr;
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
        {
            // 解析响应
           if(rm->findWork(result) == 3)
           {
               rm->findData(result);
               return new User(rm->UID, rm->Name);
           }
           else
           {
               qDebug() << "用户名或密码错误！";
           }
        }

//        close(socket);
        return nullptr;
    }

}
