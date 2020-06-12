#ifndef REGIST_H
#define REGIST_H
#include "user.h"
#include "utils.h"
#include <QDebug>
#include "registmessage.h"

class Regist
{
public:
    Regist();
    static User* auth(QString name, QString psw, QString apsw);
};

#endif // REGIST_H
