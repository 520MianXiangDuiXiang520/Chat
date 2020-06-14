#include "RegistResponseMessage.h"


RegistResponseMessage::RegistResponseMessage()
{
}


RegistResponseMessage::~RegistResponseMessage()
{
}

void RegistResponseMessage::getData(char* message)
{
	this->size = 0;
	this->type = this->getType(message);
	// cout << "type:" << this->type << endl;
	this->work = this->getWork(message);
	// cout << "work:" << this->work << endl;
	this->fromIP = this->getFrom(message);
	// cout << "fromIP:" << this->fromIP << endl;
	this->toIP = this->getTo(message);
	// cout << "toIP:" << this->toIP << endl;
	this->psw = this->getPSW(message);
	// cout << "psw:" << this->psw << endl;
	this->newName = this->getNewName(message);
	// cout << "newName:" << this->newName << endl;
	this->againPSW = this->getAgainPSW(message);
	// cout << "againPSW:" << this->againPSW << endl;
}
