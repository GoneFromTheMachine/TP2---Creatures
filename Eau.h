#include "Creature.h"
#pragma once

class Eau : public Creature
{
	// Eau: 
	// r´eduit tous les d´egˆats 
	// re¸cus de 10 % .
public:
	Eau();
	Eau(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	void DistributionPoints(
		const float& VIE,
		const float& ATT,
		const float& DEF) override;
	virtual ~Eau();
private:
};