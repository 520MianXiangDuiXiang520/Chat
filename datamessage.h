#ifndef DATAMESSAGE_H
#define DATAMESSAGE_H
#include "loginmessage.h"

class DataMessage : public LoginMessage
{
private:
    // 用于构造请求数据包
    int size = 0;
protected:
    void setAgainPSW(char* message, QString againPSW);
public:
    DataMessage();
    void setData(char* message, int workType, QString fromID,
                 QString toID, QString token, QString message_data);
};

#endif // DATAMESSAGE_H
