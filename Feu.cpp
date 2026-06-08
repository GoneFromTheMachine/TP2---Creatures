#include "Feu.h"
#include "Creature.h"
#include <string>
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
string Feu::ABSTRACT_PRINT_TYPE(
	const ECreatureType& TYPE) const
{
	return Creature::ABSTRACT_PRINT_TYPE(TYPE);
}
void Feu::ABSTRACT_PRINT() const
{
	Creature::ABSTRACT_PRINT();
}
void Feu::ABSTRACT_20_ATT_TOUR() const
{
	cout << "ABSTRACT_20_ATT_TOUR called" << endl;
}