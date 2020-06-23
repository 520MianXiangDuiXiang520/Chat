#include "RegistResponse.h"



RegistResponse::RegistResponse()
{
}


RegistResponse::~RegistResponse()
{
}

void RegistResponse::response(int socket, RegistResponseMessage* rrm)
{
	// cout << rrm->newName << "; " << rrm->againPSW << "; " << rrm->psw << endl;
	char message[128];
	if (rrm->againPSW == rrm->psw)
	{
		User* newUser = this->udb->addNewUser(rrm->psw, rrm->newName);
		cout << "newUser" << newUser->getUID() << endl;
		if (newUser)
		{
			LoginResponse* lr = new LoginResponse();
			lr->login(newUser->getUID(), rrm->fromIP);
			rrm->createMessage(message, '0', 3, newUser->getUID(), rrm->newName, "ttttt");
		}
		
	}
	else
	{
		rrm->createMessage(message, '0', 4);
	}
	cout << "message:" << message << endl;
	Utils::send(socket, message);
}
