#include "DataMessage.h"

DataMessage::DataMessage()
{
}

DataMessage::~DataMessage()
{
}

void DataMessage::getData(char *message)
{
    this->size = 0;
    this->type = this->getType(message);
    this->work = this->getWork(message);
    // this->fromIP = this->getFrom(message);
    this->fromID = this->getFrom(message);
    // this->toIP = this->getTo(message);
    this->toID = this->getTo(message);
    this->token = this->getToken(message);
    this->message_data = this->getMessageData(message);
}
