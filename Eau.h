#include "Creature.h"
#pragma once

class Eau : public Creature
{
	// Eau: 
	// r´eduit tous les d´egˆats re¸cus de 10 % .
public:
	float m_multiplicateur = 0.9;
	Eau();
	Eau(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	virtual ~Eau(); // le mot cle virtuel pourrait etre omi vu que le parent est virtual
	void ABSTRACT() const override;
private:
};

