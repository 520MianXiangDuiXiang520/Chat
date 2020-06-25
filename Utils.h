#pragma once
#define PORT "1999"
#define SPORT "9991"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <signal.h>
#include <sys/wait.h>
using namespace std;
#ifdef _WIN32
#include <Rpc.h>
#pragma comment(lib, "Rpcrt4.lib")
#else
//编译链接时，需要加入 -luuid
#include <uuid/uuid.h>
#endif

class Utils
{
private:
	static void read_childproc(int sig);

public:
	Utils();
	~Utils();
	static void errorHandling(std::string mes);
	static int conn();
	static int connByIP(string ip);
	static void send(int socket, char* message);
	static std::string GenerateUUID();
	static std::string GenerateUUIDWithoutDelim();
};

