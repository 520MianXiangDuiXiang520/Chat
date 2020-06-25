#ifndef LISTEN_H
#define LISTEN_H
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <string>
#include "utils.h"
#include "dialog.h"

class Listen
{
public:
    Listen();
    static void doListen(Dialog *dia);

};

#endif // LISTEN_H
