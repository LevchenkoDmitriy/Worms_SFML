#pragma once
#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

//Множество фикстур под землей
extern std::set<b2Fixture*> fixturesUnderfoot;

//Класс, который будет отвечать за проверку находится ли наш объект на земле
class MyContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* contact) {
		//фикстура A - сенсор
		void* fixtureUserData = contact->GetFixtureA()->GetUserData();
		if ((int)fixtureUserData == 3)
			fixturesUnderfoot.insert(contact->GetFixtureB());//A - низ, В - земля
															 //Проверка, что В - сенсор
		fixtureUserData = contact->GetFixtureB()->GetUserData();
		if ((int)fixtureUserData == 3)
			fixturesUnderfoot.insert(contact->GetFixtureA());
	}

	void EndContact(b2Contact* contact) {
		void* fixtureUserData = contact->GetFixtureA()->GetUserData();
		if ((int)fixtureUserData == 3)
			fixturesUnderfoot.erase(contact->GetFixtureB());
														
		fixtureUserData = contact->GetFixtureB()->GetUserData();
		if ((int)fixtureUserData == 3)
			fixturesUnderfoot.erase(contact->GetFixtureA());
	}
};

#endif