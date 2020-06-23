#pragma once
#include<iostream>
#include<string>
using namespace std;

class User
{
private:
	string uid;
	string psw;
	string name;
	void setPSW(string psw);
	string getPSW();
public:
	User(string uid, string name);
	User(string uid, string psw, string name);
	void setName(string name);
	string getName();
	void setUID(string uid);
	string getUID();
	~User();
};

