#include "Creature.h"
#pragma once

class Plante : public Creature
{
public:
	Plante();
	Plante(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	void DistributionPoints(
		const float& VIE,
		const float& ATT,
		const float& DEF) override;
	virtual ~Plante();
};