#include "MessengerSystem.h"
#include "Server.h"

MessengerSystem* MessengerSystem::instance = nullptr;

MessengerSystem::MessengerSystem()
{
}


MessengerSystem::~MessengerSystem()
{
}

MessengerSystem& MessengerSystem::getInstance()
{
	if (!instance)
		instance = new MessengerSystem;
	return *instance;
}

void MessengerSystem::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void MessengerSystem::addServer(std::string name)
{
	servers.push_back(new Server(name));
}

Server* MessengerSystem::getServerByName(std::string str)
{
	for (auto s : servers)
		if (s->getName() == str)
			return s;
}
