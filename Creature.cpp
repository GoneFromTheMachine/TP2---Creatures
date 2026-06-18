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
void CreateCreature(
	vector<Creature*>& CREATURES)
{

	// Cr´eation de cr´eatures
	// Votre premi`ere tˆache consiste 
	// `a permettre `a l’utilisateur de 
	// cr´eer des cr´eatures 
	// personnalis´ees.
	string inputName;
	string inputType;
	int inputVie;
	int inputAtt;
	int inputDef;

	while (true)
	{
		system("cls");
		cout << endl;
		cout << "---------------------" << endl;
		cout << "| Creation Creature |" << endl;
		cout << "---------------------" << endl;
		cout << "donner inputVie: ";
		cin >> inputVie;
		cout << endl;
		cout << "donner inputAtt: ";
		cin >> inputAtt;
		cout << endl;
		cout << "donner inputDef: ";
		cin >> inputDef;
		cout << endl;

		if (inputVie == 0 ||
			inputAtt == 0 ||
			inputDef == 0)
		{
			system("cls");
			cout << "une des 3 entrees est invalide" << endl;
			cout << "inputVie: " << inputVie << endl;
			cout << "inputAtt: " << inputAtt << endl;
			cout << "inputDef: " << inputDef << endl;
			cout << "creature ne vas pas etre construite" << endl;
			cout << "donner un numero valide qui n'est pas 0" << endl;
			system("pause");
			continue;
		}
		else
		{
			//if (inputType == Creature::PrintType(ECreatureType::Eau))
			//{

			//}
			CREATURES.push_back(new Electrique(
				"Electricite pure",
				15,
				55,
				0));
			//m_vie = inputVie;
			//m_vie = inputAtt;
			//m_vie = inputDef;
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
void Creature::DistributionPoints(
	const float& VIE,
	const float& ATT,
	const float& DEF)
{


	cout << endl;
	// assignation VIE
	if (m_ptsDistrubution > VIE)
	{
		m_vie = VIE;
		m_ptsDistrubution -= VIE;
		cout << "assignation VIE ";
		cout << m_vie << " ";
		cout << "points de distributions restants: ";
		cout << m_ptsDistrubution << endl;
	}
	else
	{
		m_vie = m_ptsDistrubution;
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



	if (m_ptsDistrubution > 0)
	{
		m_vie += m_ptsDistrubution / 3;
		m_att += m_ptsDistrubution / 3;
		m_def += m_ptsDistrubution / 3;
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