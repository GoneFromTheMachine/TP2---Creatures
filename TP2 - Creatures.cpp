#include <iostream>
#include "Creature.h"
#include "Electrique.h"
#include "Plante.h"
#include "Feu.h"
#include "Eau.h"
#include "TP2 - Creatures.h"
#include <vector>
#include <cstdlib>
using namespace std;

vector<Creature*> g_creatures = {};

int main()
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

	g_creatures.push_back(new Plante());
	g_creatures.push_back(new Plante(
		"fleur", 
		333.0f, 
		33.1f,
		12.3f));
	g_creatures.push_back(new Feu());
	g_creatures.push_back(new Feu(
		"flamme eternelle",
		123123.13f,
		12377.9f,
		12234.3f));
	g_creatures.push_back(new Electrique());
	g_creatures.push_back(new Electrique(
		"Electricite pure",
		1313.12f,
		1233.22f,
		777.33));
	g_creatures.push_back(new Eau());
	g_creatures.push_back(new Eau(
		"Riviere",
		1634.12f,
		1343.22f,
		744.33f));

	system("pause");
	MenuCreatures(g_creatures);
	Delete();
}

void MenuCreatures(const vector<Creature*>& CREATURES)
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
			AfficherCreatures(CREATURES);
			continue;
		case 'b':
		case 'B':
			StatsCreature(CREATURES);
			continue;
		case 'c':
		case 'C':
			ModCreature(CREATURES);
			continue;
		case 'd':
		case 'D':
			DeleteCreature(CREATURES);
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

void AfficherCreatures(const vector<Creature*>& CREATURES)
{
	system("cls");
	cout << endl;
	cout << "---------------------" << endl;
	cout << "| showing creatures |" << endl;
	cout << "---------------------" << endl;
	for (int i = 0; i < CREATURES.size(); i++)
		CREATURES[i]->Print();
	system("pause");
}
void StatsCreature(const vector<Creature*>& CREATURES)
{
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
void ModCreature(const vector<Creature*>& CREATURES)
{
	system("cls");
	cout << "change creatures" << endl;
	system("pause");
}
void DeleteCreature(const vector<Creature*>& CREATURES)
{
	system("cls");
	cout << "delete creatures" << endl;
	system("pause");
}

void Delete()
{
	cout << endl;
	cout << "deleting all objects" << endl;

	for (int i = 0; i < g_creatures.size(); i++)
		delete g_creatures[i];
}