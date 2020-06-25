#include "listen.h"

Listen::Listen()
{

}

void Listen::doListen(Dialog *dia)
{
    socklen_t adr_sz;
    int clnt_sock;
    int serv_sock;
    serv_sock = utils::conn();


    struct sockaddr_in clnt_adr;
    while (1)
    {
        adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr*) & clnt_adr, &adr_sz);
        if (clnt_sock == -1)
            continue;
        else
            puts("new client connected...");
        close(serv_sock);
        char result[2048];

        while (read(clnt_sock, result, 2048 - 1) > 0)
        {
            dia->setMessage("hello world");
            qDebug() << "result: " << result;
        }
        close(clnt_sock);
        break;
    }
    //close(serv_sock);
}
