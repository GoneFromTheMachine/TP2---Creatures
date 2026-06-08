#include "Electrique.h"
#include "Creature.h"
#include <string>
#include <iostream>
using namespace std;

Electrique::Electrique() :
	Creature(
		"Electrique par defaut",
		ECreatureType::Electrique,
		11.0f,
		22.0f,
		1444.0f)
{
	// Electrique : 
	// poss`ede 20% de chances de 
	// r´ep´eter son attaque une seconde fois.
	// TODO : implementer la chance de 20% de repeter 
	// l'attaque une seconde fois ABSTRACT PURE CLASS
	cout << "... creature detruite d'electrique ";
	cout << "avec id# " << m_id << endl;
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
	// Electrique : 
	// poss`ede 20% de chances de 
	// r´ep´eter son attaque une seconde fois.
	cout << "... et la creature est une Electrique ";
	cout << "avec id# " << endl;
	cout << m_id << endl;
}
Electrique::~Electrique()
{
	cout << "... creature detruite d'electrique ";
	cout << "avec id# " << m_id << endl;
}
string Electrique::ABSTRACT_PRINT_TYPE(
	const ECreatureType& TYPE) const
{
	return Creature::ABSTRACT_PRINT_TYPE(TYPE);
}
void Electrique::ABSTRACT_PRINT() const
{
	Creature::ABSTRACT_PRINT();
}
void Electrique::ABSTRACT_20_ATT_TOUR() const
{
	cout << "ABSTRACT_20_ATT_TOUR called" << endl;
}