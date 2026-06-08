#include "Creature.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Creature::s_creatureCount = 0;

Creature::Creature(
	const string& NAME,
	const ECreatureType& TYPE,
	const float& VIE,
	const float& ATT,
	const float& DEF) :
	m_id(++s_creatureCount),
	m_name(NAME),
	m_type(TYPE),
	m_vie(VIE),
	m_att(ATT),
	m_def(DEF)
{
	cout << "creature cree avec params #";
	cout << m_id << endl;
}
Creature::~Creature()
{
	s_creatureCount--;
	cout << "creature detruite restants:";
	cout << s_creatureCount << endl;
}
string Creature::PrintType(
	const ECreatureType& TYPE) const
{
	switch (TYPE)
	{
	case ECreatureType::Electrique:
		return "Electrique";
	case ECreatureType::Plante:
		return "Plante";
	case ECreatureType::Eau:
		return "Eau";
	case ECreatureType::Feu:
		return "Feu";
	default:
		return "INVALID TYPE";
	}
}
void Creature::Print() const
{
	cout << endl;
	cout << "printing creature info" << endl;
	cout << "id: " << m_id << endl;
	cout << "name: " << m_name << endl;
	cout << "type: " << PrintType(m_type) << endl;
	cout << "vie: " << m_vie << endl;
	cout << "att: " << m_att << endl;
	cout << "def: " << m_def << endl;
	cout << endl;
}
void Creature::StatsCreature(
	const vector<Creature*>& CREATURES) const
{
	while (true)
	{
		int input = 0;
		system("cls");
		cout << endl;
		cout << "showing stats creatures" << endl;
		cout << "------------------------------" << endl;
		cout << "| showing one creature stats |" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < CREATURES.size(); i++)
			cout << "(" << i << ") " << CREATURES[i]->m_name << endl;
		cout << "(-1)" << " return to menu" << endl;
		cin >> input;
		if (input < 0 &&
			input > CREATURES.size() &&
			input != -1)
		{
			cout << "invalid input" << endl;
			continue;
		}
		else if (input == -1)
			return;
		else
		{
			CREATURES[input]->Print();
			system("pause");
		}
	}
}
void Creature::ModCreature(
	const vector<Creature*>& CREATURES) const
{
	//system("cls");
	//cout << "change creatures" << endl;
	//system("pause");
}
void Creature::DeleteCreature(
	const vector<Creature*>& CREATURES) const
{
	//system("cls");
	//cout << "delete creatures" << endl;
	//system("pause");
}