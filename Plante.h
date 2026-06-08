#include "Creature.h"
#pragma once
class Plante : public Creature
{
	// Plante : 
	// r´eg´en`ere 5% de ses points de vie 
	// `a la fin de chaque tour.
public:
	Plante();
	Plante(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	virtual ~Plante();  // le mot cle virtuel pourrait etre omi vu que le parent est virtual
	void ABSTRACT() const override; // override de methode virtuelle pure (aussi appele methode virtuelle pure)
private:
};

