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

    /**
     * 在基类中，offset需要由其他方法指定，造成代码冗余
     * 因此重写此方法，设置offset为默认参数，在方法内部通过
     * 私有属性 size 计算出偏移量。
     * @brief setLenMessage
     * @param message: 要构造的请求数据包
     * @param data:    要往数据包中加入的数据
     * @param offset:  该字段在数据包中的偏移量
     */
    void setLenMessage(char *message, QString data, int offset=0);
public:
    RegistMessage();
    void setData(char* message, int workType, QString fromIP,
                 QString toIP, QString PSW, QString name, QString againPSW);
};

#endif // REGISTMESSAGE_H
