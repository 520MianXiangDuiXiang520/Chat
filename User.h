#pragma once
#include<iostream>
#include<string>
using namespace std;

class User
{
private:
	int uid;
	string psw;
	string name;
	void setPSW(string psw);
	string getPSW();
public:
	User(int uid, string name);
	User(int uid, string psw, string name);
	void setName(string name);
	string getName();
	void setUID(int uid);
	int getUID();
	~User();
};

