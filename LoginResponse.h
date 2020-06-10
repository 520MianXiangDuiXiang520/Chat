#pragma once
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <string>
#include "Utils.h"
#include "UserDB.h"
#include "LoginResponseMessage.h"

#define MAX_LOGIN_MESSAGE_LEN 128

class LoginResponse
{
private:
	void process_recv(int clnt_sock);
public:
	LoginResponse();
	~LoginResponse();
	void response();
};

