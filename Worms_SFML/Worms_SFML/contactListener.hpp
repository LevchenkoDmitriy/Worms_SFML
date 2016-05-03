#pragma once
#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

class contactListener {
public:
	void BeginContact(b2Contact* contact) {
		//check if fixture A was the foot sensor
		void* fixtureUserData = contact->GetFixtureA()->GetUserData();
		if ((int)fixtureUserData == 3)
			numFootContacts++;
		//check if fixture B was the foot sensor
		fixtureUserData = contact->GetFixtureB()->GetUserData();
		if ((int)fixtureUserData == 3)
			numFootContacts++;
};

#endif