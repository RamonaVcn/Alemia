#pragma once

#include <string>
#include <vector>

class Credentials;
class Connection;
class User;

class Server
{
private:
	bool status;
	std::string name;
	std::string file;
	std::vector<Credentials*> connectedUsers;
	std::vector<Connection*> connections;
	unsigned currentID;

public:
	Server(std::string file);
	~Server();

	void setStatus(bool);
	std::string getName();
	std::vector<Credentials*>& getConnectedUsers();
	unsigned generateID();
	void addCredentials(Credentials*);
	void transmitMessage(User* sender, User* receiver, std::string message);
};

