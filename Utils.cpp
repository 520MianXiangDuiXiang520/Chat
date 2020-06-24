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

void Utils::send(int socket, char* message)
{
	write(socket, message, strlen(message));
}

std::string Utils::GenerateUUID()
{
	std::string guid("");
#ifdef _WIN32
	UUID uuid;
	if (RPC_S_OK != UuidCreate(&uuid))
	{
		return guid;
	}
	char tmp[37] = {0};
	sprintf_s(tmp, "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
			  uuid.Data1, uuid.Data2, uuid.Data3,
			  uuid.Data4[0], uuid.Data4[1],
			  uuid.Data4[2], uuid.Data4[3],
			  uuid.Data4[4], uuid.Data4[5],
			  uuid.Data4[6], uuid.Data4[7]);
	guid.assign(tmp);
#else
	uuid_t uuid;
	char str[50] = {};
	uuid_generate(uuid);
	uuid_unparse(uuid, str);
	guid.assign(str);
#endif
	return guid;
}

std::string Utils::GenerateUUIDWithoutDelim()
{
	std::string str = GenerateUUID();
	std::string uuid;
	for (auto &i : str)
	{
		if ('-' != i)
		{
			uuid += i;
		}
	}
	return uuid;
}