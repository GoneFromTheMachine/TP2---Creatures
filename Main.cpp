#include <iostream>
#include "Creature.h"
#include "Electrique.h"
#include "Plante.h"
#include "Feu.h"
#include "Eau.h"
#include "Main.h"
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	vector<Creature*> creatures = {};
	CreaturesDefaultAdd(creatures);
	MenuCreatures(creatures);
	Delete(creatures);
}
void CreaturesDefaultAdd(
	vector<Creature*>& CREATURES)
{
	/*
	Dans ce deuxi`eme TP de programmation orient´ee
	objet,
	vous devrez r´ealiser un syst`eme de
	gestion et de combat de cr´eatures en console.
	Ce travail teste non seulement votre
	compr´ehension des concepts
	de programmation orient´ee objet, mais ´egalement
	votre capacit´e `a
	concevoir une architecture logicielle claire et
	r´eutilisable. Ce travail doit ˆetre r´ealis´e en
	´equipe de deux ´etudiants.
	L’utilisation de collections, de l’h´eritage,
	du polymorphisme, des m´ethodes
	virtuelles et des constructeurs/destructeurs
	avec h´eritage est obligatoire.
	*/
	CREATURES.push_back(new Plante());
	CREATURES.push_back(new Plante(
		"fleur",
		55,
		77,
		22));
	CREATURES.push_back(new Feu());
	CREATURES.push_back(new Feu(
		"flamme eternelle",
		33,
		44,
		12));
	CREATURES.push_back(new Electrique());
	CREATURES.push_back(new Electrique(
		"Electricite pure",
		15,
		55,
		24));
	CREATURES.push_back(new Eau());
	CREATURES.push_back(new Eau(
		"Riviere",
		12,
		55,
		33));
	system("pause");
}
void MenuCreatures(
	const vector<Creature*>& CREATURES)
{
	char input = ' ';
	while (true)
	{
		system("cls");
		cout << endl;
		cout << "--------" << endl;
		cout << "| MENU |" << endl;
		cout << "--------" << endl;
		cout << "(a) AfficherCreatures" << endl;
		cout << "(b) statsCreature" << endl;
		cout << "(c) modCreature" << endl;
		cout << "(d) deleteCreature" << endl;
		cout << "(e) quit" << endl;
		cout << endl;
		cin >> input;
		switch (input)
		{
		case 'a':
		case 'A':
			MenuAfficherCreatures(CREATURES);
			continue;
		case 'b':
		case 'B':
			MenuStatsCreature(CREATURES);
			continue;
		case 'c':
		case 'C':
			MenuModCreature(CREATURES);
			continue;
		case 'd':
		case 'D':
			MenuDeleteCreature(CREATURES);
			continue;
		case 'e':
		case 'E':
			cout << "quitting program" << endl;
			return;
		default:
			cout << "invalid input" << endl;
			system("pause");
			continue;
		}
	}
}
void MenuAfficherCreatures(
	const vector<Creature*>& CREATURES)
{
	// • Afficher toutes les cr´eatures 
	// existantes
	system("cls");
	cout << endl;
	cout << "---------------------" << endl;
	cout << "| showing creatures |" << endl;
	cout << "---------------------" << endl;
	for (int i = 0; i < CREATURES.size(); i++)
		CREATURES[i]->Print();
	system("pause");
}
void MenuStatsCreature(
	const vector<Creature*>& CREATURES)
{
	// • Consulter les statistiques d’une 
	// cr´eature
	while (true)
	{
		int input = 0;
		system("cls");
		cout << endl;
		cout << "showing stats creatures" << endl;
		cout << "------------------------------" << endl;
		cout << "| showing one creature stats |" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < CREATURES.size(); i++)
			cout << "(" << i << ") " << CREATURES[i]->m_name << endl;
		cout << "(-1)" << " return to menu" << endl;
		cin >> input;
		if (input < 0 && 
			input > CREATURES.size() &&
			input != -1)
		{
			cout << "invalid input" << endl;
			continue;
		}
		else if (input == -1)
			return;
		else
		{
			CREATURES[input]->Print();
			system("pause");
		}


	}
}
void MenuModCreature(
	const vector<Creature*>& CREATURES)
{
	// • Modifier une cr´eature existante
	system("cls");
	cout << "change creatures" << endl;
	system("pause");
}
void MenuDeleteCreature(
	const vector<Creature*>& CREATURES)
{
	// • Supprimer une cr´eature
	// Lorsqu’une cr´eature est supprim´ee, 
	// elle doit ˆetre retir´ee correctement 
	// de la collection.
	system("cls");
	cout << "delete creatures" << endl;
	system("pause");
}
void Delete(
	const vector<Creature*>& CREATURES)
{
	cout << endl;
	cout << "deleting all objects" << endl;

	for (int i = 0; i < CREATURES.size(); i++)
		delete CREATURES[i];
}