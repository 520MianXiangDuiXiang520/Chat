#include "UserDB.h"



UserDB::UserDB()
{
	int dbport;
	std::string ip;
	std::string user;
	std::string password;
	string db;
	const char ConfigFile[] = "config.conf";
	Config configSettings(ConfigFile);
	dbport = configSettings.Read("dbport", dbport);
	ip = configSettings.Read("dbip", ip);
	user = configSettings.Read("dbuser", user);
	password = configSettings.Read("dbpsw", password);
	db = configSettings.Read("db", db);
	cout << ip << "; " << dbport << "; " << user << "; " << password << "; " << db << endl;
	this->conn = mysql_real_connect(conn, ip.c_str(), user.c_str(), password.c_str(), db.c_str(), dbport, NULL, 0);
	if (!conn)
	{
		perror("mysql_real_connect");
		exit(1);
	}
}

User * UserDB::addNewUser(string psw, string name)
{
	// 产生随机UID
	srand((int)time(0));
	
	for (int i = 0; i < 5; i++)
	{
		string uid = "";
		for (int i = 0; i < 3; i++)
			uid = uid + std::to_string((rand() % 999 + 100));
		cout << uid << endl;
		string uidSQL = "SELECT * FROM User WHERE UID='" + uid + "';";
		if (mysql_query(conn, uidSQL.c_str()))
		{
			MYSQL_RES *result = mysql_store_result(conn);
			mysql_free_result(result);
			string sql = "INSERT INTO User(UID, PSW, addr, username) VALUES ('" + uid + "', '" + psw + "' , " + "'0.0.0.0', '" + name + "');";
			int res = mysql_query(conn, sql.c_str());
			if (!res)
			{
				return new User(uid, name);
			}
			else
			{
				printf("mysql_query: %s\n", mysql_error(conn));
				exit(1);
			}
		}
	}
	
	return nullptr;
}

User* UserDB::authUser(string stringUid, string psw)
{
	string sql = "SELECT UID, username FROM User WHERE UID= " + stringUid + " AND PSW= '" + psw + "' ;";
	int res = mysql_query(conn, sql.c_str());
	if (!res)
	{
		// 获取结果集
		MYSQL_RES *result = mysql_store_result(conn);
		if (result)
		{
			MYSQL_ROW row = mysql_fetch_row(result);
			if(row)
			{
				return new User(row[0], row[1]);
			}
			    
		}
		mysql_free_result(result);
	}
	else
	{
		cout << "no this user" << endl;
	}
	return nullptr;
}

void UserDB::updateAddr(string stringIndex, string addr)
{
	string sql = "UPDATE User SET addr= '" + addr + "' WHERE UID= " + stringIndex + " ;";
	int res = mysql_query(conn, sql.c_str());
	if (res)
	{
		printf("mysql_query: %s\n", mysql_error(conn));
		exit(1);
	}
}

void UserDB::updateToken(string uid, string token)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	string snow = std::to_string(1900 + ltm->tm_year) + "-" + std::to_string(ltm->tm_mon) + "-" + std::to_string(ltm->tm_mday) + " " + std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec);
	string sql = "INSERT INTO Token(uid, token, create_time) VALUES ('" + uid + "', '" + token + "', '" + snow + "');";
	// cout << sql << endl;
	int res = mysql_query(conn, sql.c_str());
	if (res)
	{
		printf("mysql_query: %s\n", mysql_error(conn));
	}
}

bool UserDB::isOnLine(string uid, string token)
{
    string sql = "SELECT create_time FROM Token WHERE UID = '" + uid +
	"' AND token = '" + token + "' ;";
	int a = mysql_query(conn, sql.c_str());
	// 释放结果集
	MYSQL_RES *result = mysql_store_result(conn);
	mysql_free_result(result);
	return !a;
}

	UserDB::~UserDB()
{
	mysql_close(conn);
}
