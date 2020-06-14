#include "RegistResponse.h"



RegistResponse::RegistResponse()
{
}


RegistResponse::~RegistResponse()
{
}

void RegistResponse::response(int socket, RegistResponseMessage* rrm)
{
	cout << rrm->newName << "; " << rrm->againPSW << "; " << rrm->psw << endl;
	char message[128];
	if (rrm->againPSW == rrm->psw)
	{
		User* newUser = this->udb->addNewUser(rrm->psw, rrm->newName);
		if (newUser)
		{
			LoginResponse* lr = new LoginResponse();
			lr->login(std::to_string(newUser->getUID()), rrm->fromIP);
			rrm->createMessage(message, '0', 3, std::to_string(newUser->getUID()), rrm->newName, "ttttt");
			cout << "message:" << message << endl;
		}
	}
	else
	{
		rrm->createMessage(message, '0', 4);
	}
	Utils::send(socket, message);
}
