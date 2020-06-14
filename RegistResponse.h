#pragma once
#include "RegistResponseMessage.h"
#include "User.h"
#include "UserDB.h"
#include "Utils.h"
#include "LoginResponse.h"
class RegistResponse
{
private:
	UserDB* udb = new UserDB();
public:
	RegistResponse();
	~RegistResponse();
	void response(int socket, RegistResponseMessage* rrm);
};

