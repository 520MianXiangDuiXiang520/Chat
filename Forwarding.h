#pragma once
#include "DataMessage.h"
#include "User.h"
#include "UserDB.h"
#include "Utils.h"

class Forwarding
{
private:
    UserDB *udb = new UserDB();

public:
    Forwarding();
    ~Forwarding();
    void doForward(DataMessage *dm);
    
};