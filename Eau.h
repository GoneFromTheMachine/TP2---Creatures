#include "Creature.h"
#include <string>
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
	string ABSTRACT_PRINT_TYPE(const ECreatureType& TYPE) const override; // override de methode virtuelle pure (aussi appele methode virtuelle pure)
	void ABSTRACT_PRINT() const override;  // override de methode virtuelle pure (aussi appele methode virtuelle pure)
	void ABSTRACT_20_ATT_TOUR() const override;
private:
};