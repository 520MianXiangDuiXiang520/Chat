#include "LoginResponse.h"




void LoginResponse::process_recv(int clnt_sock)
{
	puts("process_recv start");
	LoginResponseMessage* lrm = new LoginResponseMessage();
	UserDB* udb = new UserDB();
	char result[MAX_LOGIN_MESSAGE_LEN];
	//int type;
	while (read(clnt_sock, result, MAX_LOGIN_MESSAGE_LEN - 1) != 0)
	{
		lrm->getData(result);
		User* user = udb->authUser(lrm->uid, lrm->psw);
		char message[128];
		if (user)
		{
			udb->updateAddr(lrm->uid, lrm->fromIP);
			udb->updateState(lrm->uid);
			std::cout << user->getName() << "login success" << std::endl;
			lrm->createMessage(message, '0', 1, lrm->uid, user->getName(), "ttttt");
			cout << "message:" << message << endl;
			
		}
		else
		{
			lrm->createMessage(message, '0', 2);
			std::cout << "ai xi ba" << std::endl;
		}
		write(clnt_sock, message, strlen(message));
		//std::cout << "Type:" << lrm->type << std::endl;
		//std::cout << "UID: " << lrm->uid << std::endl << "PSW: " << lrm->psw << std::endl;
	}

	puts("process_recv end");
}

LoginResponse::LoginResponse()
{
}


LoginResponse::~LoginResponse()
{
}

void LoginResponse::response()
{
	socklen_t adr_sz;
	int clnt_sock;
	int serv_sock = Utils::conn();
	struct sockaddr_in clnt_adr;
	pid_t pid;
	while (1)
	{
		adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*) & clnt_adr, &adr_sz);
		if (clnt_sock == -1)
			continue;
		else
			puts("new client connected...");
		pid = fork();
		// ����
		if (pid == -1)
		{
			close(clnt_sock);
			continue;
		}
		//�ӽ���
		if (pid == 0)
		{
			close(serv_sock);
			// �����ͻ��˴��������ݲ�������Ӧ
			process_recv(clnt_sock);
			//close(clnt_sock);
			break;
		}
	}
	//close(serv_sock);
}
