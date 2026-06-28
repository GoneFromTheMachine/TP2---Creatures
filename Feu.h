#pragma once
#include "Creature.h"

class Feu : public Creature
{
public:
	Feu();
	Feu(
		const std::string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	void DistributionPoints(
		const float& VIE,
		const float& ATT,
		const float& DEF) override;
	virtual ~Feu();
};