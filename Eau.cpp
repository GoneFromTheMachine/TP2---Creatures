#include "Eau.h"
#include "Creature.h"
#include <iostream>
using namespace std;

Eau::Eau()
{
	// Eau: 
	// r´eduit tous les d´egˆats re¸cus de 10 % .
	m_type = ECreatureType::Eau;
	cout << "... et la creature est d'Eau id# " << endl;
	cout << m_id << endl;
	m_att *= m_multiplicateur;
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