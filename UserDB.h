#pragma once
#include<iostream>
#include<string>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include </usr/include/mysql/mysql.h>
#include "User.h"
#include "Config.h"
using namespace std;

class UserDB
{
private:
	MYSQL *conn = mysql_init(NULL);
public:
	UserDB();
	User* addNewUser(string psw, string name);
	User* authUser(string stringUid, string psw);
	void updateAddr(string stringIndex, string addr);
	void updateState(string stringIndex);
	~UserDB();
};

