#include "LoginResponseMessage.h"


LoginResponseMessage::LoginResponseMessage()
{
}


LoginResponseMessage::~LoginResponseMessage()
{
}

void LoginResponseMessage::getData(char* message)
{
	this->size = 0;
	this->type = this->getType(message);
	this->work = this->getWork(message);
	this->fromIP = this->getFrom(message);
	this->toIP = this->getTo(message);
	this->psw = this->getPSW(message);
	this->uid = this->getUID(message);
}
