#include "Creature.h"
#pragma once

class Plante : public Creature
{
	// Plante : 
	// r´eg´en`ere 5% de ses 
	// points de vie 
	// `a la fin de chaque tour.
public:
	Plante();
	Plante(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	virtual ~Plante();
	string ABSTRACT_PRINT_TYPE(
		const ECreatureType& TYPE) 
		const override;
	void ABSTRACT_PRINT() 
		const override;
	void ABSTRACT_20_ATT_TOUR() 
		const override;
private:
};