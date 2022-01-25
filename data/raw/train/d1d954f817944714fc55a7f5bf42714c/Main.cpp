#include "MessengerSystem.h"
#include "User.h"

#include <iostream>



int main()
{
	MessengerSystem& ms = MessengerSystem::getInstance();
	ms.addServer("Yahoo");
	ms.getServerByName("Yahoo")->setStatus(true);
	User* u1 = new User();
	User* u2 = new User();

	u1->signIn(ms.getServerByName("Yahoo"), 1, "132");
	u2->signIn(ms.getServerByName("Yahoo"), 2, "12");
	

	getchar();
	return 0;
}