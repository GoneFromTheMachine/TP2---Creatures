#include "Creature.h"
#pragma once

class Eau : public Creature
{
	// Eau: 
	// r´eduit tous les d´egˆats 
	// re¸cus de 10 % .
public:
	Eau();
	Eau(
		const string& NAME,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	virtual ~Eau();
	string ABSTRACT_PRINT_TYPE(
		const ECreatureType& TYPE) 
		const override;
	void ABSTRACT_PRINT() 
		const override;
	void ABSTRACT_20_ATT_TOUR() 
		const override;
private:
};