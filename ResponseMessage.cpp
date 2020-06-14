#include "ResponseMessage.h"



std::string ResponseMessage::getXXX(char* message)
{
	return std::string();
}

ResponseMessage::ResponseMessage()
{
}


ResponseMessage::~ResponseMessage()
{
}

std::string ResponseMessage::getLenMessage(char* message, int offset)
{
	int len = message[offset];
	char from[len];
	for (int i = 0; i < len; i++)
	{
		from[i] = message[i + offset + 1];
	}
	return std::string(from, len);
}

char ResponseMessage::getType(char* message)
{
	char type = message[this->size];
	this->size += 1;
	return type;
}

int ResponseMessage::getWork(char* message)
{
	int work = (int)message[this->size];
	this->size += 1;
	return work;
}

std::string ResponseMessage::getFrom(char* message)
{
	int len = message[this->size];
	std::string result = this->getLenMessage(message, this->size);
	this->size += len + 1;
	return result;
}

std::string ResponseMessage::getTo(char* message)
{
	int len = (int)message[this->size];
	std::string result = getLenMessage(message, this->size);
	this->size += len + 1;
	return result;
}

std::string ResponseMessage::getPSW(char* message)
{
	int len = (int)message[this->size];
	std::string result = getLenMessage(message, this->size);
	this->size += len + 1;
	return result;
}

std::string ResponseMessage::getUID(char* message)
{
	int len = (int)message[this->size];
	std::string result = getLenMessage(message, this->size);
	this->size += len + 1;
	return result;
}

std::string ResponseMessage::getAgainPSW(char* message)
{
	int len = (int)message[this->size];
	std::string result = getLenMessage(message, this->size);
	this->size += len + 1;
	return result;
}

std::string ResponseMessage::getNewName(char* message)
{
	int len = (int)message[this->size];
	std::string result = getLenMessage(message, this->size);
	this->size += len + 1;
	return result;
}

char* ResponseMessage::setType(char* message, char type)
{
	message[0] = type;
	return message;
}

char* ResponseMessage::setWork(char* message, int work)
{
	message[1] = work;
	return message;
}

char* ResponseMessage::setData(char* message, string data)
{
	int _len = data.length();
	message[this->len] = _len;
	for (int i = 0; i < _len; i++)
	{
		message[this->len + i + 1] = data[i];
	}
	this->len += _len + 1;
	return message;
}

char* ResponseMessage::setUID(char* message, string uid)
{
	if (uid.length() <= 10)
		this->setData(message, uid);
	return message;
}

char* ResponseMessage::setName(char* message, string name)
{
	if (name.length() <= 20)
		this->setData(message, name);
	return message;
}

char* ResponseMessage::setToken(char* message, string token)
{
	if (token.length() <= 64)
		this->setData(message, token);
	return message;
}

void ResponseMessage::createMessage(char* message, char type, int work, string uid, string name, string token)
{
	this->len = 2;
	message = this->setType(message, type);
	message = this->setWork(message, work);
	message = this->setUID(message, uid);
	message = this->setName(message, name);
	message = this->setToken(message, token);
}

void ResponseMessage::createMessage(char* message, char type, int work)
{
	this->len = 2;
	this->setType(message, type);
	this->setWork(message, work);
}

