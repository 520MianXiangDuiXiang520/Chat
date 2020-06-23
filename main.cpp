#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <string>
#include "Utils.h"
#include "UserDB.h"
#include "LoginResponse.h"
#include "RegistResponse.h"
#define MAX_LOGIN_MESSAGE_LEN 128

int main()
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
		if (pid == -1)
		{
			cout << "CLOSE" << endl;
			close(clnt_sock);
			continue;
		}
		if (pid == 0)
		{
			close(serv_sock);
			char result[MAX_LOGIN_MESSAGE_LEN];
			
			while (read(clnt_sock, result, MAX_LOGIN_MESSAGE_LEN - 1) > 0)
			{
				ResponseMessage* rm = new ResponseMessage();
				char type = rm->getType(result);
				int work = rm->getWork(result);
				if (type == '0')
				{
					if (work == 1)
					{
						LoginResponseMessage* lrm = new LoginResponseMessage();
						lrm->getData(result);
						LoginResponse* lr = new LoginResponse();
						lr->response(clnt_sock, lrm);
					}
					else if (work == 2)
					{
						RegistResponseMessage* rrm = new RegistResponseMessage();
						rrm->getData(result);
						RegistResponse* rr = new RegistResponse();
						rr->response(clnt_sock, rrm);
					
					}
				}
				else if (type == '1')
				{

				}
			}
			//close(clnt_sock);
			break;
		}
		else
		{

		}
	}
	//close(serv_sock);
	/*return nullptr;
	LoginResponse* lr = new LoginResponse();
	lr->response();*/
	return 0;
}