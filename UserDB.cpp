#include "UserDB.h"



UserDB::UserDB()
{
}

User* UserDB::addNewUser(string psw, string name)
{
	this->PSWS[this->INDEX] = psw;
	this->UIDS[this->INDEX] = this->INDEX;
	this->NAMES[this->INDEX] = name;
	this->INDEX++;
	User* newUser = new User(this->INDEX, psw, name);
	return newUser;
}

User* UserDB::authUser(string stringUid, string psw)
{
	int uid = std::stoi(stringUid);
	if (uid >= 100)
		return nullptr;
	else
	{
		if (this->PSWS[uid] == psw)
			return new User(uid, this->NAMES[uid]);
		else
			return nullptr;
	}
	return nullptr;
}

void UserDB::updateAddr(string stringIndex, string addr)
{
	int index = std::stoi(stringIndex);
	if (index < 100 && index > 0)
		this->ADDR[index] = addr;
}

void UserDB::updateState(string stringIndex)
{
	int index = std::stoi(stringIndex);
	this->ONLINE[index] = !this->ONLINE[index];
}



UserDB::~UserDB()
{
}
