#include "user.h"

User::User(QString uid, QString username)
{
    this->UID = uid;
    this->username = username;
}
QString User::getUID()
{
	return this->UID;
}

void User::setUID(QString uid)
{
	this->UID = uid;
}

QString User::getPSW()
{
	return this->PSW;
}

void User::setPSW(QString psw)
{
    this->PSW = psw;
}

QString User::getUsername()
{
	return this->username;
}

void User::setUsername(QString username)
{
	this->username = username;
}

QString User::getAddr()
{
	return this->addr;
}

void User::setAddr(QString addr)
{
    this->addr = addr;
}
