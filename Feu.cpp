#include "Feu.h"
#include "Creature.h"
#include <string>
#include <iostream>
using namespace std;

Feu::Feu() :
	Creature(
		"Feu par defaut",
		ECreatureType::Feu,
		10,
		2,
		1)
{
	cout << "... et la creature est un Feu avec id# " << endl;
	cout << m_id << endl;
	m_attRapide = "Flamme";
	m_attNormale = "Boule de feu";
	m_attPuissante = "Explosion";
	m_attUltime = "Brasier";
	DistributionPoints(
		10, 
		2,
		1);
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
		ATT,
		DEF)
{
	cout << "... et la creature est une Feu avec id# " << endl;
	cout << m_id << endl;
	m_attRapide = "Flamme";
	m_attNormale = "Boule de feu";
	m_attPuissante = "Explosion";
	m_attUltime = "Brasier";
	DistributionPoints(
		VIE, 
		ATT, 
		DEF);
}
void Feu::DistributionPoints(
	const float& VIE,
	const float& ATT,
	const float& DEF)
{
	// Feu : 
	// inflige 10% de d´egˆats suppl´ementaires.
	Creature::DistributionPoints(
		VIE, 
		ATT*1.1f, 
		DEF);
}
Feu::~Feu() 
{
	cout << "... creature detruite de feu " << endl;
	cout << " avec id# " << m_id << endl;
}