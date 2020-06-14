#pragma once
#include "LoginResponseMessage.h"
#include "User.h"
#include "UserDB.h"
#include "Utils.h"


class LoginResponse
{
private:
	UserDB* udb = new UserDB();
public:
	LoginResponse();
	~LoginResponse();
	void login(std::string uid, std::string fromIP);
	void response(int socket, LoginResponseMessage* lrm);
};

