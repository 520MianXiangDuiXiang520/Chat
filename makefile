server: User.o Utils.o Config.o UserDB.o LoginResponse.o LoginResponseMessage.o RegistResponseMessage.o RegistResponse.o ResponseMessage.o
	g++ User.o Utils.o Config.o UserDB.o LoginResponse.o LoginResponseMessage.o RegistResponseMessage.o RegistResponse.o ResponseMessage.o main.cpp -l mysqlclient -o server
Utils.o: Utils.h Utils.cpp
	g++ -c Utils.cpp
UserDB.o: UserDB.h UserDB.cpp User.o Config.o
	g++ -c UserDB.cpp -l mysqlclient
User.o: User.h User.cpp
	g++ -c User.cpp
LoginResponse.o: User.o UserDB.o Utils.o LoginResponseMessage.o LoginResponse.h LoginResponse.cpp
	g++ -c LoginResponse.cpp
LoginResponseMessage.o: ResponseMessage.o LoginResponseMessage.cpp
	g++ -c LoginResponseMessage.cpp
RegistResponse.o: User.o UserDB.o Utils.o LoginResponse.o RegistResponseMessage.o RegistResponse.h RegistResponse.cpp
	g++ -c RegistResponse.cpp
RegistResponseMessage.o: ResponseMessage.o RegistResponseMessage.h RegistResponseMessage.cpp
	g++ -c RegistResponseMessage.cpp
ResponseMessage.o: ResponseMessage.h ResponseMessage.cpp
	g++ -c ResponseMessage.cpp
Config.o: Config.h Config.cpp
	g++ -c Config.cpp
clear:
	rm *.o
