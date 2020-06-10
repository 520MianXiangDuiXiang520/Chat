#pragma once
#define PORT "1999"
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



class Utils
{
private:
	static void read_childproc(int sig);

public:
	Utils();
	~Utils();
	static void errorHandling(std::string mes);
	static int conn();
};

