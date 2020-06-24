#include "user.h"
#include "utils.h"
#include "loginmessage.h"

#ifndef LOGIN_H
#define LOGIN_H
#define MAX_LOGIN_MESSAGE_LEN 128


class login
{
private:
    // static void sendMessage(int sock, char *message);
    // static void readMessage(int sock, char *resault);
public:
    login();
    static User* auth(int conn, QString uid, QString psw);
};

#endif // LOGIN_H
