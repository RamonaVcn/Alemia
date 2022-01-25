#pragma once

#include <string>
#include <vector>
#include "Credentials.h"

class Server;

class User
{
private:
	std::vector<Credentials*> credentials;

public:
	User();
	~User();

	void signIn(Server* s, unsigned ID, std::string pass);
	void sendMessage(Server*s, User* u, std::string str);
	std::vector<Credentials*>& getCredentials();
};

