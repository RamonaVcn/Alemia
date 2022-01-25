#pragma once

#include <string>

class Server;

class Credentials
{
private:
	std::string pass;
	unsigned ID;
	Server* server;
	bool status;

public:
	Credentials(std::string, unsigned, Server*);
	~Credentials();

	void setStatus(bool);
	unsigned getID();
	std::string getPass();
};

