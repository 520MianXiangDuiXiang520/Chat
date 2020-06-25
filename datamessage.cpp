#include "datamessage.h"

DataMessage::DataMessage()
{

}

void DataMessage::setData(char* message, int workType, QString fromID,
                          QString toID, QString token, QString message_data)
{
    this->size = 0;
    this->setType(message);
    this->setWork(message, workType);
//    this->setFrom(message, fromIP);
    this->setElse(message, fromID);
    this->setElse(message, toID);
    this->setElse(message, token);
    this->setElse(message, message_data);
}
