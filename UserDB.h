#pragma once
#include<iostream>
#include<string>
#include "User.h"
using namespace std;

class UserDB
{
private:
	std::string UIDS[100] = { "0", "1", "2" };
	std::string PSWS[100] = { "junebao","junebao2", "junebao3" };
	std::string NAMES[100] = { "aJuneBao", "OOP", "Class" };
	std::string ADDR[100] = { "127.0.0.1", "127.0.0.1", "127.0.0.1" };
	bool ONLINE[100] = { false };
	int INDEX = 3;
public:
	UserDB();
	User* addNewUser(string psw, string name);
	User* authUser(string stringUid, string psw);
	void updateAddr(string stringIndex, string addr);
	void updateState(string stringIndex);
	~UserDB();
};

