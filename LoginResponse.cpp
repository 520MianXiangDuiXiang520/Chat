#include "LoginResponse.h"

LoginResponse::LoginResponse()
{
}


LoginResponse::~LoginResponse()
{
}

void LoginResponse::login(std::string uid, std::string fromIP)
{
	udb->updateAddr(uid, fromIP);
	// udb->updateState(uid);
}

void LoginResponse::response(int socket, LoginResponseMessage* lrm)
{
	User* user = udb->authUser(lrm->uid, lrm->psw);
	char message[128];
	if (user)
	{
		this->login(lrm->uid, lrm->fromIP);
		std::cout << user->getName() << "login success" << std::endl;
		lrm->createMessage(message, '0', 1, lrm->uid, user->getName(), "ttttt");
		cout << "message:" << message << endl;
	}
	else
	{
		lrm->createMessage(message, '0', 2);
		std::cout << "ai xi ba" << std::endl;
	}
	Utils::send(socket, message);
}
