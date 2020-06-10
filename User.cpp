#include "User.h"


User::User(int uid, string name)
{
	this->uid = uid;
	this->name = name;
}

User::User(int uid, string psw, string name)
{
	this->uid = uid;
	this->name = name;
	this->psw = psw;
}

void User::setPSW(string psw)
{
	this->psw = psw;
}

string User::getPSW()
{
	return this->psw;
}

void User::setName(string name)
{
	this->name = name;
}

string User::getName()
{
	return this->name;
}

void User::setUID(int uid)
{
	this->uid = uid;
}

int User::getUID()
{
	return this->uid;
}

User::~User()
{
}
