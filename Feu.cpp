#include "Feu.h"
#include "Creature.h"
#include <iostream>
using namespace std;

Feu::Feu() :
	Creature(
		"Feu par defaut",
		ECreatureType::Feu,
		10.0f,
		2.0f * 1.1f,
		1.0f)
{
	// Feu : 
	// inflige 10% de d´egˆats suppl´ementaires.
	cout << "... et la creature est un Feu avec id# " << endl;
	cout << m_id << endl;
}
Feu::Feu(
	const string& NAME,
	const float& VIE,
	const float& ATT,
	const float& DEF) :
	Creature(
		NAME,
		ECreatureType::Feu,
		VIE,
		ATT * 1.1f,
		DEF)
{
	// Feu : 
	// inflige 10% de d´egˆats suppl´ementaires.
	cout << "... et la creature est une Feu avec id# " << endl;
	cout << m_id << endl;
}

Feu::~Feu() 
{
	cout << "... creature detruite de feu " << endl;
	cout << " avec id# " << m_id << endl;
}
void Feu::ABSTRACT() const
{
	cout << "ABSTRACT feu called" << endl;
}