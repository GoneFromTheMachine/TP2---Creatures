#include "Plante.h"
#include "Creature.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Plante::Plante() : 
	Creature(
	"plante par defaut",
	ECreatureType::Plante,
	10,
	2,
	1)
{
	cout << "... et la creature est une Plante avec id# " << endl;
	cout << m_id << endl;
	m_attRapide = "Racine";
	m_attNormale = "Liane";
	m_attPuissante = "Epine";
	m_attUltime = "Foret vivante";
	DistributionPoints(
		10, 
		2, 
		1);
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
	cout << "... et la creature est une Plante avec id# " << endl;
	cout << m_id << endl;
	m_attRapide = "Racine";
	m_attNormale = "Liane";
	m_attPuissante = "Epine";
	m_attUltime = "Foret vivante";
	DistributionPoints(
		VIE, 
		ATT, 
		DEF);
}
void Plante::DistributionPoints(
	const float& VIE,
	const float& ATT,
	const float& DEF)
{
	// Plante : 
	// r´eg´en`ere 5% de ses points de vie 
	// `a la fin de chaque tour.
	Creature::DistributionPoints(
		VIE, 
		ATT, 
		DEF);
	m_regenPerTurn = 0.05f;
}
Plante::~Plante()
{
	cout << "... creature detruite plante " << endl;
	cout << " avec id# " << m_id << endl;
}