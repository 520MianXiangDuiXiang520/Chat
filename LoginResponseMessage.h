#pragma once
#include <string>
#include <iostream>
using namespace std;

class LoginResponseMessage
{
private:
	int size = 0;
	int len = 2;
	std::string getLenMessage(char* message, int offset);
	int getType(char* message);
	int getWork(char* message);
	std::string getFrom(char* message);
	std::string getTo(char* message);
	std::string getPSW(char* message);
	std::string getUID(char* message);
	char* setType(char* message, char type);
	char* setWork(char* message, int work);
	char* setData(char* message, string data);
	char* setUID(char* message, string uid);
	char* setName(char* message, string name);
	char* setToken(char* message, string token);

public:
	int type;
	int work;
	std::string fromIP;
	std::string toIP;
	std::string psw;
	std::string uid;
	LoginResponseMessage();
	~LoginResponseMessage();
	void getData(char* message);
	void createMessage(char* message, char type, int work,
		string uid, string name, string token);
	void createMessage(char* message, char type, int work);
};

