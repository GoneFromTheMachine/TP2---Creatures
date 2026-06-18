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
		0,
		77,
		22));
	CREATURES.push_back(new Feu());
	CREATURES.push_back(new Feu(
		"flamme eternelle",
		33,
		0,
		12));
	CREATURES.push_back(new Electrique());
	CREATURES.push_back(new Electrique(
		"Electricite pure",
		15,
		55,
		0));
	CREATURES.push_back(new Eau());
	CREATURES.push_back(new Eau(
		"Riviere",
		0,
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
		cout << "(e) combat" << endl;
		cout << "(f) quit" << endl;
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
			MenuCombat(CREATURES);
			continue;
		case 'f':
		case 'F':
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
	cout << "vector creatures size: " << CREATURES.size() << endl;
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

}
void MenuCombat(
	const vector<Creature*>& CREATURES)
{ 
	int input = 0;
	int currentSelectedFighters = 0;
	int maxFighters = 2;
	vector<int> selectedIds = {};
	if (CREATURES.size() < maxFighters)
	{
		cout << "pas assez de creatures" << endl;
		return;
	}
	while (true)
	{
		system("cls");
		cout << endl;
		cout << "-------------------------------" << endl;
		cout << "| Combat: Choisir combattants |" << endl;
		cout << "-------------------------------" << endl;
		cout << "creatures selectionnes:" << endl;
		for (int i = 0; i < selectedIds.size(); i++)
			cout << i << ": " << CREATURES[selectedIds[i]]->m_name << endl;
		cout << endl;
		for (int i = 0; i < CREATURES.size(); i++)
			cout << "(" << i << ") " << CREATURES[i]->m_name << endl;
		cout << "(-1)" << " return to menu" << endl;
		cin >> input;
		if ((input < 0 && input != -1) ||
			(input > CREATURES.size() && input != -1))
		{
			cout << "invalid input" << endl;
			system("pause");
			continue;
		}
		else if (input == -1)
			return;
		else
		{
			// S´election des combattants
			// Une fois des cr´eatures cr´e´ees, 
			// l’utilisateur doit pouvoir d´emarrer 
			// un combat.
			// Deux cr´eatures existantes sont alors 
			// s´electionn´ees parmi la collection.
			// Les statistiques compl`etes des deux 
			// combattants doivent ˆetre affich´ees 
			// avant le d´ebut du
			// combat.
			// debut combat



			if (currentSelectedFighters < maxFighters)
			{

				cout << "selected fighter: ";
				cout << "Name: " << CREATURES[input]->m_name << endl;
				cout << "ID: " << CREATURES[input]->m_id << endl;
				selectedIds.push_back(CREATURES[input]->m_id);
				currentSelectedFighters++;
				cout << endl;
				system("pause");
			}

			system("cls");
			cout << "selectedIds.size()" << selectedIds.size() << endl;
			for (int i = 0; i < selectedIds.size(); i++)
				for (int j = 0; j < CREATURES.size(); j++)
					if (CREATURES[j]->m_id == selectedIds[i])
					{
						cout << "(" << i << ") ";
						cout << CREATURES[j]->m_name;
						cout << " ID: ";
						cout << CREATURES[j]->m_id << endl;
					}
			cout << endl;

			if (currentSelectedFighters >= maxFighters)
			{
				system("cls");
				//cout << endl;
				//for (int i = 0; i < selectedIds.size(); i++)
				//	for (int j = 0; j < CREATURES.size(); j++)
				//		if (CREATURES[j]->m_id == selectedIds[i])
				//		{
				//			cout << "(" << i << ") ";
				//			cout << CREATURES[j]->m_name;
				//			cout << " ID: ";
				//			cout << CREATURES[j]->m_id << endl;
				//		}
				//cout << endl;
				system("pause");
				system("cls");
				cout << "all fighters selected" << endl;
				cout << "STARTING BATTLE";
				system("pause");
				Combat(CREATURES, selectedIds);
				return;
			}
			continue;
		}
	}
}
void Combat(
	const vector<Creature*>& CREATURES,
	const vector<int> SELECTED)
{
	/*
	Afficher les statistiques des deux creature au 
	debut du combat
	Tour simultanne
	Joueur 1: 
	Choisir type attaque
	[W]Atq1 
	[A]Atq2
	[S]Atq3
	[D]Atq4
	Joueur 2:
	Choisir type attaque
	[W]Atq1 
	[A]Atq2
	[S]Atq3
	[D]Atq4
	Calculer les attaques avant de les appliquer
	Infliger les degat au deux creature peut importe s'il meurt ou pas
	En cas de double mort = match nul
	*/
	system("cls");
	cout << "combat" << endl;
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