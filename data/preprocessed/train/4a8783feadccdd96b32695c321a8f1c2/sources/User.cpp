#include <iostream>

#include "Server.h"
#include "User.h"

User::User()
{
}

User::~User()
{
}

void User::signIn(Server * s, unsigned ID, std::string pass)
{
	std::vector<Credentials*>& connectedUsers = s->getConnectedUsers();

	for(auto u:connectedUsers)
		if(u->getID() == ID)
			if (u->getPass() != pass)
			{
				std::cout << "Parola incorecta!\n";
				return;
			}
			else
			{
				std::cout << "Autentificarea utilizatorului in serverul " << s->getName() << " reusita!\n";
				u->setStatus(true);
				return;
			}

	Credentials* c = new Credentials(pass, s->generateID(), s);
	this->credentials.push_back(c);
	s->addCredentials(c);
	c->setStatus(true);
}

void User::sendMessage(Server * s, User * u, std::string str)
{
	s->transmitMessage(this, u, str);
}

std::vector<Credentials*>& User::getCredentials()
{
	return credentials;
}
