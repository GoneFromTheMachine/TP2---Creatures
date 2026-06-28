#pragma once
#include "Creature.h"

class Electrique : public Creature
{
public:
	Electrique();
	Electrique(
		const std::string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	void DistributionPoints(
		const float& VIE,
		const float& ATT,
		const float& DEF) override;
	virtual ~Electrique();
};