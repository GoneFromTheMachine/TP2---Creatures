#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class ECreatureType 
{
	Electrique,
	Plante,
	Eau,
	Feu,
	Count
};
class Creature
{
public:
	static int s_creatureCount;
	int m_id;
	float m_vie;
	float m_att;
	float m_def;
	float m_chanceDoubleAtt = 0;
	float m_regenPerTurn = 0;
	float m_ptsDistrubution = 100.0f;
	ECreatureType m_type;
	std::string m_name;
	std::string m_attRapide;
	std::string m_attNormale;
	std::string m_attPuissante;
	std::string m_attUltime;
	Creature(
		const std::string& NAME,
		const ECreatureType& TYPE,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	virtual ~Creature();
	std::string PrintType(
		const ECreatureType& TYPE) 
		const;
	void Print() 
		const;
	void ModificationNameType(
		const std::string& NAME,
		const ECreatureType& TYPE);
	// methode virtuelle pure:
	virtual void DistributionPoints(
		const float& VIE,
		const float& ATT,
		const float& DEF) = 0;
};