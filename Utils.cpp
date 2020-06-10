#include "Utils.h"
#include <iostream>
using namespace std;


void Utils::errorHandling(string mes)
{
	cout << mes << endl;
}

Utils::Utils()
{
}


Utils::~Utils()
{
}

void Utils::read_childproc(int sig)
{
	pid_t pid;
	int status;
	pid = waitpid(-1, &status, WNOHANG);
	printf("removed proc id: %d \n", pid);
}

int Utils::conn()
{
	int serv_sock;
	struct sockaddr_in serv_adr;
	struct sigaction act;
	int state;

	act.sa_handler = Utils::read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	// �ӽ�����ֹ��ִ��read_childproc
	state = sigaction(SIGCHLD, &act, 0);
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(PORT));

	if (bind(serv_sock, (struct sockaddr*) & serv_adr, sizeof(serv_adr)) == -1)
		errorHandling("bind() error");
	if (listen(serv_sock, 6) == -1)
		errorHandling("listen() error");
	printf("%d", &serv_sock);
	return serv_sock;
}
