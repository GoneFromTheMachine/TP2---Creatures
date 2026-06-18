#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma once

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
	string m_name;
	ECreatureType m_type;
	float m_vie;
	float m_att;
	float m_def;
	float m_chanceDoubleAtt = 1;
	float m_regenPerTurn = 0;
	float m_ptsDistrubution = 100.0f;
	Creature(
		const string& NAME,
		const ECreatureType& TYPE,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	virtual ~Creature();
	string PrintType(
		const ECreatureType& TYPE) 
		const;
	void Print() 
		const;
	void ModificationNameType(
		const string& NAME,
		const ECreatureType& TYPE);
	virtual void DistributionPoints(
		const float& VIE,
		const float& ATT,
		const float& DEF) = 0;
};