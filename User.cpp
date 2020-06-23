#include "User.h"

User::User(string uid, string name)
{
	this->uid = uid;
	this->name = name;
}

User::User(string uid, string psw, string name)
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

void User::setUID(string uid)
{
	this->uid = uid;
}

string User::getUID()
{
	return this->uid;
}

User::~User()
{
}
