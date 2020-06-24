#include "registmessage.h"

RegistMessage::RegistMessage()
{

}



void RegistMessage::setAgainPSW(char *message, QString againPSW)
{
    int offset = strlen(message);
    LoginMessage::setLenMessage(message, againPSW, offset);
    this->size = offset + againPSW.length() + 1;
}

void RegistMessage::setData(char *message, int workType, QString fromIP, QString toIP, QString PSW, QString name, QString againPSW)
{
    this->size = 0;
    this->setType(message);
    this->setWork(message, workType);
    this->setFrom(message, fromIP);
    this->setTo(message, toIP);
    this->setPSW(message, PSW);
    this->setUID(message, name);
    this->setAgainPSW(message, againPSW);
//    this->setSize(message);
}
