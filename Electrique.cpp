#include "Electrique.h"
#include "Creature.h"
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
	cout << "... et la creature est une Electrique avec id# " << endl;
	cout << m_id << endl;
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
	cout << "... et la creature est une Electrique avec id# " << endl;
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