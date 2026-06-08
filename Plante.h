#include "Creature.h"
#include <string>
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
	string ABSTRACT_PRINT_TYPE(const ECreatureType& TYPE) const override; // override de methode virtuelle pure (aussi appele methode virtuelle pure)
	void ABSTRACT_PRINT() const override; // override de methode virtuelle pure (aussi appele methode virtuelle pure)
	void ABSTRACT_20_ATT_TOUR() const override;
private:
};