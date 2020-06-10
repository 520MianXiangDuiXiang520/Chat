#include "utils.h"




utils::utils()
{

}

QSqlDatabase utils::connMysql()
{
    //connect mysql-server
    QSqlDatabase d=QSqlDatabase::addDatabase("QMYSQL");//加载mysql驱动，这个字符串是固定的
    d.setHostName("127.0.0.1");
    d.setDatabaseName("junechat");        //数据库名称
    d.setPort(10067);                     //数据库端口，如果没有更改/etc/mysql/my.cnf就不用改
    d.setUserName("root");
    d.setPassword("root");
    if(d.open())
       qDebug()<<"数据库连接成功";
    else
       qDebug()<<"数据库连接失败";

    return d;
}


QString utils::getLocalIP()
{
    int inet_sock;
    struct ifreq ifr;
    char ip[32];
    char *result;
    inet_sock = socket(AF_INET, SOCK_DGRAM, 0);
    strcpy(ifr.ifr_name, "wifi0");
    ioctl(inet_sock, SIOCGIFADDR, &ifr);
    strcpy(ip, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
    result = (char *)malloc(sizeof(char) * (sizeof(ip) + 1));
    strncpy(result, ip, sizeof(ip));
    return QString(QLatin1String(result));
}


int utils::conn(QString connIP)
{
    int sock;
    struct sockaddr_in serv_adr;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(connIP.toUtf8().data());
    serv_adr.sin_port = htons(atoi(PORT));

    if (connect(sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        errorHandling("connect() error!");
    return sock;
}

void utils::errorHandling(QString mes)
{
    qDebug()<<mes;
    exit(1);
}
