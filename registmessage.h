#ifndef REGISTMESSAGE_H
#define REGISTMESSAGE_H
#include "loginmessage.h"

class RegistMessage : public LoginMessage
{
private:
    // 用于构造请求数据包
    int size = 0;
protected:
    void setAgainPSW(char* message, QString againPSW);
public:
    RegistMessage();
    void setData(char* message, int workType, QString fromIP,
                 QString toIP, QString PSW, QString name, QString againPSW);
};

#endif // REGISTMESSAGE_H
