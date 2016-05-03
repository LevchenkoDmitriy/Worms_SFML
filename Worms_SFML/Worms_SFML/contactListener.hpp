#pragma once
#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

//��������� ������� ��� ������
extern std::set<b2Fixture*> fixturesUnderfoot;

//�����, ������� ����� �������� �� �������� ��������� �� ��� ������ �� �����
class MyContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* contact) {
		//�������� A - ������
		void* fixtureUserData = contact->GetFixtureA()->GetUserData();
		if ((int)fixtureUserData == 3)
			fixturesUnderfoot.insert(contact->GetFixtureB());//A - ���, � - �����
															 //��������, ��� � - ������
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