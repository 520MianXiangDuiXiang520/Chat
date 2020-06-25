#pragma once
#include "ResponseMessage.h"
class DataMessage : public ResponseMessage
{
private:
    int size;

public:
    DataMessage();
    ~DataMessage();
    void getData(char *message);
};