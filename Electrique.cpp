#include "Electrique.h"
#include "Creature.h"
#include <string>
#include <iostream>
using namespace std;

Electrique::Electrique() :
	Creature(
		"Electrique par defaut",
		ECreatureType::Electrique,
		5,
		25,
		66)
{
	cout << "... creature detruite d'electrique ";
	cout << "avec id# " << m_id << endl;
	DistributionPoints(
		5, 
		25, 
		66);
}
Electrique::Electrique(
	const string& NAME,
	const float& VIE,
	const float& ATT,
	const float& DEF) :
	Creature(
		NAME,
		ECreatureType::Electrique,
		VIE,
		ATT,
		DEF)
{
	cout << "... et la creature est une Electrique ";
	cout << "avec id# " << endl;
	cout << m_id << endl;
	DistributionPoints(
		VIE, 
		ATT, 
		DEF);
}
void Electrique::DistributionPoints(
	const float& VIE,
	const float& ATT,
	const float& DEF)
{
	// Electrique : 
	// poss`ede 20% de chances de 
	// r´ep´eter son attaque une seconde fois.
	Creature::DistributionPoints(
		VIE, 
		ATT, 
		DEF);
	m_chanceDoubleAtt = 0.2f;
}
Electrique::~Electrique()
{
	cout << "... creature detruite d'electrique ";
	cout << "avec id# " << m_id << endl;
}