#include "Eau.h"
#include "Creature.h"
#include <string>
#include <iostream>
using namespace std;

Eau::Eau() :
	Creature(
		"Eau par defaut",
		ECreatureType::Eau,
		55,
		11,
		55)
{
	cout << "... et la creature est un Eau avec id# " << endl;
	cout << m_id << endl;
	DistributionPoints(55, 11, 55);
}
Eau::Eau(
	const string& NAME,
	const float& VIE,
	const float& ATT,
	const float& DEF) :
	Creature(
		NAME,
		ECreatureType::Eau,
		VIE,
		ATT,
		DEF)
{
	cout << "... et la creature est une Eau avec id# " << endl;
	cout << m_id << endl;
	DistributionPoints(VIE, ATT, DEF);
}


void Eau::DistributionPoints(
	const float& VIE,
	const float& ATT,
	const float& DEF)
{
	// Eau: 
	// r´eduit tous les d´egˆats re¸cus de 10 % .
	Creature::DistributionPoints(
		VIE, 
		ATT, 
		DEF*1.1f);
}

Eau::~Eau()
{
	cout << "... creature detruite d'eau " << endl;
	cout << " avec id# " << m_id << endl;
}