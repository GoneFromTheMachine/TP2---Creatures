#include "Creature.h"
#include <iostream>
#include <string>
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
string Creature::ABSTRACT_PRINT_TYPE(const ECreatureType& TYPE) const
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
void Creature::ABSTRACT_PRINT() const
{
	cout << endl;
	cout << "printing creature info" << endl;
	cout << "id: " << m_id << endl;
	cout << "name: " << m_name << endl;
	cout << "type: " << ABSTRACT_PRINT_TYPE(m_type) << endl;
	cout << "vie: " << m_vie << endl;
	cout << "att: " << m_att << endl;
	cout << "def: " << m_def << endl;
	cout << endl;
}