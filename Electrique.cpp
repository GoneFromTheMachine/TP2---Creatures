#include "Electrique.h"
#include "Creature.h"
#include <iostream>
using namespace std;

Electrique::Electrique()
{
	// Electrique : 
	// poss`ede 20% de chances de 
	// r´ep´eter son attaque une seconde fois.
	m_type = ECreatureType::Electrique;
	cout << "... et la creature est electrique avec id# " << endl;
	cout << m_id << endl;
}
Electrique::~Electrique()
{
	cout << "... creature detruite d'electrique " << endl;
	cout << " avec id# " << m_id << endl;
}
void Electrique::ABSTRACT() const
{
	cout << "ABSTRACT Electrique called" << endl;
}