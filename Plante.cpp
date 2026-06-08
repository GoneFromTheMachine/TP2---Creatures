#include "Plante.h"
#include "Creature.h"
#include <string>
#include <iostream>
using namespace std;

Plante::Plante() : 
	Creature(
	"plante par defaut",
	ECreatureType::Plante,
	10.0f,
	2.0f,
	1.0f)
{
	// Plante : 
	// r´eg´en`ere 5% de ses points de vie 
	// `a la fin de chaque tour.
	cout << "... et la creature est une Plante avec id# " << endl;
	cout << m_id << endl;
}
Plante::Plante(
	const string& NAME,
	const float& VIE,
	const float& ATT,
	const float& DEF) :
	Creature(
	NAME,
	ECreatureType::Plante,
	VIE,
	ATT,
	DEF)
{
	// Plante : 
	// r´eg´en`ere 5% de ses points de vie 
	// `a la fin de chaque tour.
	cout << "... et la creature est une Plante avec id# " << endl;
	cout << m_id << endl;
}
Plante::~Plante()
{
	cout << "... creature detruite plante " << endl;
	cout << " avec id# " << m_id << endl;
}
string Plante::ABSTRACT_PRINT_TYPE(const ECreatureType& TYPE) const
{
	return Creature::ABSTRACT_PRINT_TYPE(TYPE);
}
void Plante::ABSTRACT_PRINT() const
{
	Creature::ABSTRACT_PRINT();
}
void Plante::ABSTRACT_20_ATT_TOUR() const
{
	cout << "ABSTRACT_20_ATT_TOUR called" << endl;
	// Plante : 
	// r´eg´en`ere 5% de ses points de vie 
	// `a la fin de chaque tour.
}