#include "Creature.h"
#pragma once

class Electrique : public Creature
{
	// Electrique : 
	// poss`ede 20% de chances de 
	// r´ep´eter son attaque une seconde fois.
public:
	Electrique();
	Electrique(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	virtual ~Electrique();  // le mot cle virtuel pourrait etre omi vu que le parent est virtual
	void ABSTRACT() const override; // override de methode virtuelle pure (aussi appele methode virtuelle pure)
	void ABSTRACT_20_ATT_TOUR() const override;
private:
};