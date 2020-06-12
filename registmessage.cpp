#include "registmessage.h"

RegistMessage::RegistMessage()
{

}

void RegistMessage::setLenMessage(char *message, QString data, int offset)
{
    offset = this->size;
    message[offset] = (char)data.length();

    std::string ds = data.toStdString();
    for(int i = 0; i < ds.length(); i++)
    {
        message[offset + 1 + i] = ds[i];
    }
    this->size += (ds.length() + 1);
}

void RegistMessage::setAgainPSW(char *message, QString againPSW)
{
    this->setLenMessage(message, againPSW);
}

void RegistMessage::setData(char *message, int workType, QString fromIP, QString toIP, QString PSW, QString UID, QString againPSW)
{
    LoginMessage::setData(message, workType, fromIP, toIP, PSW, UID);
    this->setAgainPSW(message, againPSW);
}
