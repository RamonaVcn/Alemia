#include "Connection.h"



Connection::Connection()
{
}


Connection::~Connection()
{
}

std::vector<Credentials*>& Connection::getParticipants()
{
	return participants;
}
