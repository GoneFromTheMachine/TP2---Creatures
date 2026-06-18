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
	// Cr´eation de cr´eatures
	// Votre premi`ere tˆache consiste 
	// `a permettre `a l’utilisateur de 
	// cr´eer 
	// des cr´eatures personnalis´ees.
	// Chaque cr´eature poss`ede au 
	// minimum :
	// • Un nom
	// 	• Un type
	//	• Des points de vie
	//	• Une valeur d’attaque
	//	• Une valeur de d´efense
	// Cr´eation de cr´eatures
	// Votre premi`ere tˆache consiste 
	// `a permettre `a l’utilisateur de 
	// cr´eer des cr´eatures 
	// personnalis´ees.
	// Chaque cr´eature poss`ede au 
	// minimum :
	// • Un nom
	// • Un type
	// • Des points de vie
	// • Une valeur d’attaque
	// • Une valeur de d´efense
	// Vous devez permettre la cr´eation 
	// d’au moins quatre types de 
	// cr´eatures
	// diff´erents.
	// Par exemple :
	//  • Feu
	// 	• Eau
	//	• Plante
	//	• Electrique ´
	//	Chaque type doit ˆetre 
	// repr´esent´e par 
	//  sa propre classe d´eriv´ee.
	// Les attaques d’une cr´eature 
	// sont 
	// enti`erement d´etermin´ees par 
	// son 
	// type(toutes les cr´eatures
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
	void ModCreature(
		const vector<Creature*>& CREATURES) 
		const;
	void DeleteCreature(
		const vector<Creature*>& CREATURES) 
		const;
	virtual void DistributionPoints(
		const float& VIE,
		const float& ATT,
		const float& DEF) = 0;
private:
};