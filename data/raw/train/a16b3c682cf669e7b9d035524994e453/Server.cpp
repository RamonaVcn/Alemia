#include "Connection.h"
#include "Server.h"
#include "User.h"

Server::Server(std::string name) :name(name)
{
	status = false;
	currentID = 0;
	file = name + ".txt";
}

Server::~Server()
{
}

void Server::setStatus(bool b)
{
	status = b;
}

std::string Server::getName()
{
	return name;
}

std::vector<Credentials*>& Server::getConnectedUsers()
{
	return connectedUsers;
}

unsigned Server::generateID()
{
	return currentID++;
}

void Server::addCredentials(Credentials *c)
{
	connectedUsers.push_back(c);
}

void Server::transmitMessage(User * sender, User * receiver, std::string message)
{
	for (auto c : connections)
	{
		std::vector<Credentials*>& p = c->getParticipants();

		Credentials* senderC = nullptr;
		Credentials*receiverC = nullptr;
		for (auto pr : p)
		{
			for (auto c1 : sender->getCredentials())
				if (c1 == pr)
				{
					senderC = c1;
					break;
				}
			for(auto c2:receiver->getCredentials())
				if (c2 == pr)
				{
					receiverC = c2;
					break;
				}
		}
	}
}
