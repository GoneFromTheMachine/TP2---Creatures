#include "Creature.h"
#pragma once

class Electrique : public Creature
{
	// Electrique : 
	// poss`ede 20% de chances de 
	// r´ep´eter son attaque une 
	// seconde fois.
public:
	Electrique();
	Electrique(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	virtual ~Electrique();
	string ABSTRACT_PRINT_TYPE(
		const ECreatureType& TYPE) 
		const override;
	void ABSTRACT_PRINT() 
		const override;
	void ABSTRACT_20_ATT_TOUR() 
		const override;
private:
};