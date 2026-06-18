#include "Creature.h"
#pragma once

class Plante : public Creature
{
	// Plante : 
	// r´eg´en`ere 5% de ses 
	// points de vie 
	// `a la fin de chaque tour.
public:
	Plante();
	Plante(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	void DistributionPoints();
	virtual ~Plante();
private:
};