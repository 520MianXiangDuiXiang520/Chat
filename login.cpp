#include "login.h"

login::login()
{

}



User* login::auth(QString uid, QString psw)
{
    qDebug() << "auth:";
    // 封装请求报文
    LoginMessage *lm = new LoginMessage();
    QString localIP = utils::getLocalIP();
    QString serverIP = "192.168.1.7";
    char message[128] = {'*'};
    lm->setData(message, 1, localIP, serverIP, psw, uid);


    qDebug() << "message:";
    qDebug() << message;
    // 发送给服务端
    int socket = utils::conn(serverIP);
    write(socket, message, strlen(message));
    qDebug() << "发完了";
    // 接收服务端响应
    char result[MAX_LOGIN_MESSAGE_LEN];
    int resultLen = read(socket, result, MAX_LOGIN_MESSAGE_LEN - 1);
    qDebug() << result;
    if(resultLen <= 0)
        qDebug() << "未收到服务器响应";
    else
    {
        // 解析响应
       if(lm->findWork(result) == 1)
       {
           lm->findData(result);
           return new User(lm->UID, lm->Name);
       }
       else
       {
           qDebug() << "用户名或密码错误！";
       }
    }
    close(socket);
    return nullptr;
}
