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
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <netdb.h>
#include <net/if.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/ioctl.h>


#define PORT "1999"
#define SPORT "9991"

class utils
{
private:
    static void errorHandling(QString mes);
public:
    utils();
    static int conn(QString connIP);
    static int conn();
    static void read_childproc(int sig);
    static QSqlDatabase connMysql();
    static QString getLocalIP();
};

#endif // UTILS_H
