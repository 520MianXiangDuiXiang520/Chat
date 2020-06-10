#ifndef UTILS_H
#define UTILS_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define PORT "1999"

class utils
{
private:
    static void errorHandling(QString mes);
public:
    utils();
    static int conn(QString connIP);
    static QSqlDatabase connMysql();
    static QString getLocalIP();
};

#endif // UTILS_H
