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

int utils::getClientSocket(int serv_sock)
{
    socklen_t adr_sz;
    struct sockaddr_in clnt_adr;
    adr_sz = sizeof(clnt_adr);
    return accept(serv_sock, (struct sockaddr *)&clnt_adr, &adr_sz);
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

void utils::read_childproc(int sig)
{
    pid_t pid;
    int status;
    pid = waitpid(-1, &status, WNOHANG);
    printf("removed proc id: %d \n", pid);
}

int utils::conn()
{
    int serv_sock;
    struct sockaddr_in serv_adr;
    struct sigaction act;
    int state;

    act.sa_handler = utils::read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    state = sigaction(SIGCHLD, &act, 0);
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(SPORT));

    if (bind(serv_sock, (struct sockaddr*) & serv_adr, sizeof(serv_adr)) == -1)
    {
        errorHandling("bind() error");
        return -1;
    }


    if (listen(serv_sock, 6) == -1)
    {
        errorHandling("listen() error");
        return -1;
    }

//    printf("%d", &serv_sock);
    return serv_sock;
}

void utils::errorHandling(QString mes)
{
    qDebug()<<mes;
}
