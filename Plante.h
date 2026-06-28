#pragma once
#include "Creature.h"

class Plante : public Creature
{
public:
	Plante();
	Plante(
		const std::string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	void DistributionPoints(
		const float& VIE,
		const float& ATT,
		const float& DEF) override;
	virtual ~Plante();
};