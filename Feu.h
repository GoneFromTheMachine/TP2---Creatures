#include "Creature.h"
#pragma once

class Feu : public Creature
{
	// Feu : 
	// inflige 10% de d´egˆats 
	// suppl´ementaires.
public:
	Feu();
	Feu(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	void DistributionPoints();
	virtual ~Feu();
private:
};