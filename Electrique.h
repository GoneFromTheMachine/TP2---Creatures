#include "Creature.h"
#pragma once

class Electrique : public Creature
{
	// Electrique : 
	// poss`ede 20% de chances de 
	// r´ep´eter son attaque une 
	// seconde fois.
public:
	Electrique();
	Electrique(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	void DistributionPoints(
		const float& VIE,
		const float& ATT,
		const float& DEF) override;
	virtual ~Electrique();
private:
};