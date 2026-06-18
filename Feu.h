#include "Creature.h"
#pragma once

class Feu : public Creature
{
public:
	Feu();
	Feu(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	void DistributionPoints(
		const float& VIE,
		const float& ATT,
		const float& DEF) override;
	virtual ~Feu();
};