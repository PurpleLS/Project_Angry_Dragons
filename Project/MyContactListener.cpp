#include "MyContactListener.h"


MyContactListener::MyContactListener()
{
}


MyContactListener::~MyContactListener()
{
}

void MyContactListener::BeginContact(b2Contact* contact)
{
	// Starts listening for body collisions
	GameObject* bodyUserData1 = static_cast<GameObject*> (contact->GetFixtureA()->GetBody()->GetUserData());

	GameObject* bodyUserData2 = static_cast<GameObject*> (contact->GetFixtureB()->GetBody()->GetUserData());

	if(bodyUserData1 != nullptr && bodyUserData2 != nullptr)
		bodyUserData1->collision(*bodyUserData2);
}
