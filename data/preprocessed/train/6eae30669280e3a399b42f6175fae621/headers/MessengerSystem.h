#pragma once

#include <string>
#include <vector>

#include "Server.h"

class MessengerSystem
{
private:
	MessengerSystem();
	MessengerSystem(const MessengerSystem&);
	~MessengerSystem();

	static MessengerSystem* instance;

	std::vector<Server*> servers;

public:
	static MessengerSystem& getInstance();
	static void destroyInstance();

	void addServer(std::string);
	Server* getServerByName(std::string);
};

