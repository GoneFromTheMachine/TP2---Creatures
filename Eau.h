#include "Creature.h"
#pragma once

class Eau : public Creature
{
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
};