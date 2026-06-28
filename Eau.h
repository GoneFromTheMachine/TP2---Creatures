#pragma once
#include "Creature.h"

class Eau : public Creature
{
public:
	Eau();
	Eau(
		const std::string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	void DistributionPoints(
		const float& VIE,
		const float& ATT,
		const float& DEF) override;
	virtual ~Eau();
};