#include "Creature.h"

#pragma once
class Feu : public Creature
{
	// Feu : 
	// inflige 10% de d´egˆats suppl´ementaires.
public:
	Feu();
	Feu(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	virtual ~Feu();  // le mot cle virtuel pourrait etre omi vu que le parent est virtual
	void ABSTRACT() const override; // fonction virtuelle pure
private:
};

