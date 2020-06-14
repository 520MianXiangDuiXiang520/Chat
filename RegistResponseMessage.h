#pragma once
#include "ResponseMessage.h"
class RegistResponseMessage :
	public ResponseMessage
{
private:
	int size;
public:
	RegistResponseMessage();
	~RegistResponseMessage();
	void getData(char* message);
};

