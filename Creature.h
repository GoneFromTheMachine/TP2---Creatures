#include <iostream>
#include <string>
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
	// `a permettre `a l’utilisateur de cr´eer 
	// des cr´eatures personnalis´ees.
	// Chaque cr´eature poss`ede au minimum :
	// • Un nom
	// 	• Un type
	//	• Des points de vie
	//	• Une valeur d’attaque
	//	• Une valeur de d´efense
	// Cr´eation de cr´eatures
	// Votre premi`ere tˆache consiste 
	// `a permettre `a l’utilisateur de 
	// cr´eer des cr´eatures personnalis´ees.
	// Chaque cr´eature poss`ede au minimum :
	// • Un nom
	// • Un type
	// • Des points de vie
	// • Une valeur d’attaque
	// • Une valeur de d´efense
	// Vous devez permettre la cr´eation 
	// d’au moins quatre types de cr´eatures
	// diff´erents.
	// Par exemple :
	//  • Feu
	// 	• Eau
	//	• Plante
	//	• Electrique ´
	//	Chaque type doit ˆetre repr´esent´e par 
	//  sa propre classe d´eriv´ee.
	// Les attaques d’une cr´eature sont 
	// enti`erement d´etermin´ees par son 
	// type(toutes les cr´eatures
public:
	static int s_creatureCount;
	int m_id;
	string m_name;
	ECreatureType m_type;
	float m_vie;
	float m_att;
	float m_def;
	Creature(
		const string& NAME,
		const ECreatureType& TYPE,
		const float& VIE,
		const float& ATT,
		const float& DEF);
	virtual ~Creature();
	virtual string ABSTRACT_PRINT_TYPE(const ECreatureType& TYPE) const = 0; // methode virtuelle pure (aussi appele methode virtuelle pure)
	virtual void ABSTRACT_PRINT() const = 0; // methode virtuelle pure (aussi appele methode virtuelle pure)
	virtual void ABSTRACT_20_ATT_TOUR() const = 0;
private:
};