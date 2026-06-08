#include "Creature.h"
#pragma once

class Feu : public Creature
{
	// Feu : 
	// inflige 10% de d´egˆats 
	// suppl´ementaires.
public:
	Feu();
	Feu(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	virtual ~Feu();
	string ABSTRACT_PRINT_TYPE(
		const ECreatureType& TYPE) 
		const override;
	void ABSTRACT_PRINT() 
		const override;
	void ABSTRACT_20_ATT_TOUR() 
		const override;
private:
};