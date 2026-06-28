#include "Creature.h"
#include "Electrique.h"
#include "Feu.h"
#include "Eau.h"
#include "Plante.h"
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
void Creature::DistributionPoints(
	const float& VIE,
	const float& ATT,
	const float& DEF)
{
	m_ptsDistrubution = 100;
	cout << endl;

	if (VIE + ATT + DEF > m_ptsDistrubution)
	{
		m_vie = (m_ptsDistrubution / 3)*5;
		m_att =  m_ptsDistrubution / 3;
		m_def =  m_ptsDistrubution / 3;
		return;
	}

	// assignation VIE
	if (m_ptsDistrubution > VIE)
	{
		m_vie = VIE*5;
		m_ptsDistrubution -= VIE;
		cout << "assignation VIE ";
		cout << m_vie << " ";
		cout << "points de distributions restants: ";
		cout << m_ptsDistrubution << endl;
	}
	else
	{
		m_vie = m_ptsDistrubution*5;
		m_ptsDistrubution = 0;
		cout << "plus de pts a distribuer ";
		cout << "assignation VIE ";
		cout << m_vie << " ";
		cout << "points de distributions restants: ";
		cout << m_ptsDistrubution << endl;
	}

	// assignation ATT
	if (m_ptsDistrubution > ATT)
	{
		m_att = ATT;
		m_ptsDistrubution -= ATT;
		cout << "assignation ATT ";
		cout << m_att << " ";
		cout << "points de distributions restants: ";
		cout << m_ptsDistrubution << endl;
	}
	else
	{
		m_att = m_ptsDistrubution;
		m_ptsDistrubution = 0;
		cout << "plus de pts a distribuer ";
		cout << "assignation ATT ";
		cout << m_att << " ";
		cout << "points de distributions restants: ";
		cout << m_ptsDistrubution << endl;
	}

	// assignation DEF
	if (m_ptsDistrubution > DEF)
	{
		m_def = DEF;
		m_ptsDistrubution -= DEF;
		cout << "assignation DEF ";
		cout << m_def << " ";
		cout << "points de distributions restants: ";
		cout << m_ptsDistrubution << endl;
	}
	else
	{
		m_def = m_ptsDistrubution;
		m_ptsDistrubution = 0;
		cout << "plus de pts a distribuer ";
		cout << "assignation DEF ";
		cout << m_def << " ";
		cout << "points de distributions restants: ";
		cout << m_ptsDistrubution << endl;
	}
	
	// redistribution points
	if (m_ptsDistrubution > 0)
	{
		m_vie += (m_ptsDistrubution / 3)*5;
		m_att +=  m_ptsDistrubution / 3;
		m_def +=  m_ptsDistrubution / 3;
		m_ptsDistrubution = 0;
		cout << "points non depenses redistribues : " << endl;
		cout << "VIE: " << m_vie << endl;
		cout << "ATT: " << m_att << endl;
		cout << "DEF: " << m_def << endl;
		cout << "points de distributions restants: ";
		cout << m_ptsDistrubution << endl;
	}
	cout << endl;
}
void Creature::ModificationNameType(
	const string& NAME,
	const ECreatureType& TYPE)
{
	if (TYPE > ECreatureType::Count ||
		(int)ECreatureType(TYPE) < 0)
	{
		system("cls");
		cout << "invalid type input" << endl;
		system("pause");
	}
	m_name = NAME;
	m_type = TYPE;
}