#include "Credentials.h"

Credentials::Credentials(std::string s, unsigned i, Server *srv) :
	pass(s), ID(i), server(srv)
{
	status = false;
}

Credentials::~Credentials()
{
}

void Credentials::setStatus(bool b)
{
	status = b;
}

unsigned Credentials::getID()
{
	return ID;
}

std::string Credentials::getPass()
{
	return pass;
}
