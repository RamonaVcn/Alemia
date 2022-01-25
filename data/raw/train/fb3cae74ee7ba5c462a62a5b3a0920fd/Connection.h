#pragma once

#include <vector>

class Credentials;

class Connection
{
protected:
	std::vector<Credentials*> participants;
	std::string file;

public:
	Connection();
	~Connection();

	void sendMessage();
	std::vector<Credentials*>& getParticipants();
};

