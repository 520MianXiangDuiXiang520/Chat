#pragma once
#include <string>
#include <iostream>
#include "ResponseMessage.h"
using namespace std;

class LoginResponseMessage:
	public ResponseMessage
{
private:
	int size = 0;
	int len = 2;
public:
	LoginResponseMessage();
	~LoginResponseMessage();
	void getData(char* message);
};

