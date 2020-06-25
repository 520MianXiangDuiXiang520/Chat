#include "Forwarding.h"

Forwarding::Forwarding()
{
}

Forwarding::~Forwarding()
{
}

void Forwarding::doForward(DataMessage *dm)
{
    // 1. 判断接收者是否在线
    if(this->udb->isOnLine(dm->uid, dm->token))
    {
        // TODO: dm->toID
        int conn = Utils::connByIP("192.168.1.12");
        cout << "from ID: " << dm->fromID << endl;
        char message [2048];
        dm->createMessage(message, '0', 6, dm->fromID, dm->message_data);
        cout << "Forwarding: " << message << endl;
        write(conn, message, strlen(message));
        cout << "ok" << endl;
    }
    else
    {
        // TODO: 暂存信息，等用户上线后通知
    }
    
}