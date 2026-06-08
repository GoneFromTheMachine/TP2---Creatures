#include "Eau.h"
#include "Creature.h"
#include <iostream>
using namespace std;

Eau::Eau() :
	Creature(
		"Eau par defaut",
		ECreatureType::Eau,
		1233.01f,
		2.0f,
		1.0f * 1.1f)
{
	// Eau: 
	// r´eduit tous les d´egˆats re¸cus de 10 % .
	cout << "... et la creature est un Eau avec id# " << endl;
	cout << m_id << endl;
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
		DEF * 1.1f)
{
	// Eau: 
	// r´eduit tous les d´egˆats re¸cus de 10 % .
	cout << "... et la creature est une Eau avec id# " << endl;
	cout << m_id << endl;
}
Eau::~Eau()
{
	cout << "... creature detruite d'eau " << endl;
	cout << " avec id# " << m_id << endl;
}
void Eau::ABSTRACT() const 
{
	cout << "ABSTRACT Eau called" << endl;
}