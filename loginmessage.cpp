#include "loginmessage.h"

LoginMessage::LoginMessage()
{

}

/**
 * 设置包类型
 *   1: 心跳包，服务器收到该类包后，继续维持与该客户端的链接，
 *      并且响应最新的好友状态
 *   0: 数据包，服务器收到这类包后，按照下一位标识的不同功能解析携带的数据
 *      并按协议做不同的响应
 * @brief LoginMessage::setType
 */
void LoginMessage::setType(char * message)
{
    message[0] = '0';
    this->size += 1;
}

/**
 * 设置包的功能，使用 1 位存储，最多支持 128 种功能
 * 1, 2, 3, 4 是与登录功能相关的四类包
 *   1: 登录请求，是客户端发给服务器的，携带 UID 和 PSW
 *   2: 成功响应，服务端验证 UID，PSW 通过后响应给客户端，携带用户相关信息
 *   3: 失败响应，UID 或 PSW 错误时，响应给客户端
 *   4: 其他错误，发生服务端异常等其他错误时响应给客户端
 * @brief LoginMessage::setWork
 * @param workType
 */
void LoginMessage::setWork(char * message, char workType)
{
    if(workType > 127 ||workType < 0)
        qDebug() << "setWork error!";
    else
        message[this->size] = workType;
    this->size += 1;
}

void LoginMessage::setLenMessage(char *message,QString data, int offset)
{
    message[offset] = (char)data.length();

    std::string ds = data.toStdString();
    for(int i = 0; i < ds.length(); i++)
    {
        message[offset + 1 + i] = ds[i];
    }
}

/**
 * from 字段用来存储发送者的IP地址，偏移量为 2
 * 长度为 16 位，其中第一位用来存储IP地址的真实长度
 *
 * |    0   |      1 - 15      |
 * |--------|------------------|
 * | IP 长度 | IP地址 按char 存储|
 *
 * @brief LoginMessage::setFrom
 * @param fromIP
 */
void LoginMessage::setFrom(char * message, QString fromIP)
{
    int offset = this->size;
    setLenMessage(message, fromIP, offset);
    this->size += fromIP.length() + 1;
}

/**
 * 类似于 setFrom, 偏移量为 18
 * @brief LoginMessage::setTo
 * @param toIP
 */
void LoginMessage::setTo(char * message, QString toIP)
{
    int offset = this->size;
    setLenMessage(message, toIP, offset);
    this->size += toIP.length() + 1;
}

/**
 * 封装输入的密码，该字段占用 20 位，第一位用来标识密码长度
 * 后 19 位保存密码（密码最长 19 位），偏移量 34
 * @brief LoginMessage::setPSW
 * @param psw
 */
void LoginMessage::setPSW(char * message, QString psw)
{
    int offset = this->size;
    setLenMessage(message, psw, offset);
    this->size += psw.length() + 1;
}

void LoginMessage::setUID(char * message, QString uid)
{
    int offset = this->size;
    setLenMessage(message, uid, offset);
    this->size += uid.length() + 1;
}

void LoginMessage::setSize(char *message)
{
    int offset = this->size;
    message[offset] = (char)this->size + 1;
}

void LoginMessage::setData(char * message, int workType, QString fromIP, QString toIP, QString PSW, QString UID)
{
    this->size = 0;
    this->setType(message);
    this->setWork(message, workType);
    this->setFrom(message, fromIP);
    this->setTo(message, toIP);
    this->setPSW(message, PSW);
    this->setUID(message, UID);
    this->setSize(message);
}

int LoginMessage::getType(char *message)
{
    return (int)message[0];
}

int LoginMessage::getWork(char *message)
{
    return (int)message[1];
}

QString LoginMessage::getLenMessage(char *message, int offset)
{
    int len = (int)message[offset];
    char from[len];
    for(int i = 0; i < len; i++)
    {
        from[i] = message[i + offset + 1];
    }
    return QString(QLatin1String(from));
}

QString LoginMessage::getFrom(char *message)
{
    return getLenMessage(message, 2);
}

QString LoginMessage::getTo(char *message)
{
    return getLenMessage(message, 18);
}

QString LoginMessage::getPSW(char *message)
{
    int offset = 18 + 16;
    return getLenMessage(message, offset);
}

QString LoginMessage::getUID(char *message)
{
    int offset = 18 + 16 + 20;
    return getLenMessage(message, offset);
}

char LoginMessage::findType(char *message)
{
    if(strlen(message) >= 2)
        return message[0];
    return '\0';
}

int LoginMessage::findWork(char *message)
{
    if(strlen(message) >= 2)
        return message[1];
    return 0;
}

QString LoginMessage::findString(char *message)
{
    int _len = message[this->len];
//    qDebug() << _len;
    char from[_len];
    for (int i = 0; i < _len; i++)
    {
        from[i] = message[i + this->len + 1];
    }
    this->len += (_len + 1);
//    qDebug() << from;
    return QString::fromStdString(std::string(from, _len));
}

void LoginMessage::findData(char *message)
{
    this->len = 2;
    this->UID = this->findString(message);
    this->Name = this->findString(message);
    this->Token = this->findString(message);
}























