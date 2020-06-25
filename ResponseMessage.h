#pragma once
#include <string>
#include <iostream>
using namespace std;

class ResponseMessage
{

private:
	int size = 0;
	int len = 2;
	std::string getXXX(char* message);
public:
	char type;
	int work;
	std::string fromIP;
	std::string fromID;
	std::string toIP;
	std::string toID;
	std::string psw;
	std::string uid;
	std::string againPSW;
	std::string newName;
	std::string message_data;
	std::string token;
	ResponseMessage();
	~ResponseMessage();
	std::string getLenMessage(char* message, int offset);
	char getType(char* message);
	int getWork(char* message);
	std::string getFrom(char* message);
	std::string getTo(char* message);
	std::string getPSW(char* message);
	std::string getUID(char* message);
	std::string getAgainPSW(char* message);
	std::string getNewName(char* message);
	std::string getMessageData(char* message);
	std::string getToken(char* message);
	char* setType(char* message, char type);
	char* setWork(char* message, int work);
	char* setData(char* message, string data);
	char* setUID(char* message, string uid);
	char* setName(char* message, string name);
	char* setToken(char* message, string token);
	// void getData(char* message);
	void createMessage(char* message, char type, int work,
		string uid, string name, string token);
	void createMessage(char* message, char type, int work);
	void createMessage(char* message, char type, int work,
	 string fromID, string data);
};

