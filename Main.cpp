#include <iostream>
#include "Creature.h"
#include "Electrique.h"
#include "Plante.h"
#include "Feu.h"
#include "Eau.h"
#include "Main.h"
#include <vector>
#include <cstdlib>
#include <windows.h>
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
	vector<Creature*>& CREATURES)
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
		cout << "(f) CreateCreature" << endl;
		cout << "(g) quit" << endl;
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
			MenuCreateCreature(CREATURES);
			continue;
		case 'g':
		case 'G':
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
		if ((input < 0 && input != -1) ||
			(input > CREATURES.size() && input != -1))
		{
			system("cls");
			cout << "invalid input" << endl;
			system("pause");
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
	vector<Creature*>& CREATURES)
{
	// • Modifier une cr´eature existante
	system("cls");
	cout << "Menu Mod Creatures" << endl;
	int input;
	int mod_vie;
	int mod_att;
	int mod_def;
	int mod_type;
	string mod_name;
	while (true)
	{
		if (CREATURES.size() <= 0)
		{
			system("cls");
			cout << "Vecteur de creatures est deja vide. ";
			cout << "Retour au menu principal" << endl;
			system("pause");
			return;
		}
		system("cls");
		cout << endl;
		cout << "---------------------" << endl;
		cout << "| Menu Mod Creature |" << endl;
		cout << "---------------------" << endl;
		cout << endl;
		cout << "chosisissez une creature a modifier" << endl;
		cout << endl;
		for (int i = 0; i < CREATURES.size(); i++)
			cout << "(" << i << ") " << CREATURES[i]->m_name << endl;
		cout << "(-1)" << " return to menu" << endl;
		cin >> input;
		if ((input < 0 && input != -1) ||
			(input > CREATURES.size() && input != -1))
		{
			system("cls");
			cout << "invalid input" << endl;
			system("pause");
			continue;
		}
		else if (input == -1)
			return;
		else
		{
			while (true)
			{
				system("cls");
				cout << "donner nouvel m_vie" << endl;
				cin >> mod_vie;
				cout << "donner nouvel mod_att" << endl;
				cin >> mod_att;
				cout << "donner nouvel mod_def" << endl;
				cin >> mod_def;
				cout << "donner nouvel mod_type" << endl;
				for (int i = 0; i < static_cast<int>(ECreatureType::Count); i++)
					cout << "(" << i << ") " << CREATURES[0]->PrintType(static_cast<ECreatureType>(i)) << endl;
				cin >> mod_type;
				cout << endl;
				cout << "donner nouvel mod_name" << endl;
				cin >> mod_name;
				CREATURES[input]->DistributionPoints(
					mod_vie, 
					mod_att, 
					mod_def);
				CREATURES[input]->ModificationNameType(
					mod_name,
					static_cast<ECreatureType>(mod_type));
				system("cls");
				cout << "creature apres modification" << endl;
				CREATURES[input]->Print();
				system("pause");
				return;
			}
		}
	}
}
void MenuDeleteCreature(
	vector<Creature*>& CREATURES)
{
	// • Supprimer une cr´eature
	// Lorsqu’une cr´eature est supprim´ee, 
	// elle doit ˆetre retir´ee correctement 
	// de la collection.
	cout << "Menu Delete Creatures" << endl;
	while (true)
	{
		if (CREATURES.size() <= 0)
		{
			system("cls");
			cout << "Vecteur de creatures est deja vide. ";
			cout << "Retour au menu principal" << endl;
			system("pause");
			return;
		}
		int input = 0;
		system("cls");
		cout << endl;
		cout << "------------------------" << endl;
		cout << "| Menu Delete creature |" << endl;
		cout << "------------------------" << endl;
		cout << endl;
		cout << "chosisissez une creature a delete" << endl;
		cout << endl;
		for (int i = 0; i < CREATURES.size(); i++)
			cout << "(" << i << ") " << CREATURES[i]->m_name << endl;
		cout << "(-1)" << " return to menu" << endl;
		cin >> input;
		if ((input < 0  && input != -1) ||
			(input > CREATURES.size() && input != -1))
		{
			system("cls");
			cout << "invalid input" << endl;
			system("pause");
			continue;
		}
		else if (input == -1)
			return;
		else
		{
			system("cls");
			cout << endl;
			cout << "Creatures vector size: " << CREATURES.size() << endl;
			cout << endl;
			cout << "deleting creature: " << CREATURES[input]->m_name;
			cout << " at ID: " << CREATURES[input]->m_id << endl;
			cout << endl;
			delete CREATURES[input];
			CREATURES.erase(CREATURES.begin() + input);
			cout << endl;
			cout << "Creatures vector size: " << CREATURES.size() << endl;
			system("pause");
		}
	}
}
void MenuCreateCreature(
	vector<Creature*>& CREATURES)
{
	// Cr´eation de cr´eatures
	// Votre premi`ere tˆache consiste 
	// `a permettre `a l’utilisateur de 
	// cr´eer des cr´eatures 
	// personnalis´ees.
	int inputVie;
	int inputAtt;
	int inputDef;
	int inputType;
	string inputName;

	while (true)
	{
		system("cls");
		cout << endl;
		cout << "---------------------" << endl;
		cout << "| Creation Creature |" << endl;
		cout << "---------------------" << endl;
		cout << "donner inputVie: ";
		cin >> inputVie;
		cout << endl;
		cout << "donner inputAtt: ";
		cin >> inputAtt;
		cout << endl;
		cout << "donner inputDef: ";
		cin >> inputDef;
		cout << endl;

		for (int i = 0; i < (int)ECreatureType::Count; i++)
			cout << "(" << i << ") " << CREATURES[0]->PrintType(static_cast<ECreatureType>(i)) << endl;

		cout << "donner inputType: ";
		cin >> inputType;
		cout << endl;

		cout << endl;
		cout << "donner inputName: ";
		cin >> inputName;
		cout << endl;

		cout << "static_cast<int>(ECreatureType::Count " << static_cast<int>(ECreatureType::Count) << endl;
		if (inputVie == 0 ||
			inputAtt == 0 ||
			inputDef == 0 ||
			inputType > (int)ECreatureType::Count ||
			inputType < 0)
		{
			system("cls");
			cout << "---------" << endl;
			cout << "| Error |" << endl;
			cout << "---------" << endl;
			cout << "une des 3 entrees est invalide" << endl;
			cout << endl;
			cout << "inputVie: " << inputVie << endl;
			cout << "inputAtt: " << inputAtt << endl;
			cout << "inputDef: " << inputDef << endl;
			cout << "inputType: " << inputType << endl;
			cout << "inputName: " << inputName << endl;
			cout << endl;
			cout << "creature ne vas pas etre construite" << endl;
			cout << "donner un numero valide qui n'est pas 0 pour die, att, def" << endl;
			cout << "ou le type n'est pas parmis les choix de types permis" << endl;
			system("pause");
			inputVie = 1;
			inputAtt = 1;
			inputDef = 1;
			continue;
		}
		else
		{
			if (inputType == (int)ECreatureType::Electrique)
				CREATURES.push_back(new Electrique(
					inputName,
					inputVie,
					inputAtt,
					inputDef));
			if (inputType == (int)ECreatureType::Eau)
				CREATURES.push_back(new Eau(
					inputName,
					inputVie,
					inputAtt,
					inputDef));
			if (inputType == (int)ECreatureType::Feu)
				CREATURES.push_back(new Feu(
					inputName,
					inputVie,
					inputAtt,
					inputDef));
			if (inputType == (int)ECreatureType::Plante)
				CREATURES.push_back(new Plante(
					inputName,
					inputVie,
					inputAtt,
					inputDef));
			system("cls");
			cout << "nouvelle creature cree" << endl;
			CREATURES.back()->Print();
			system("pause");
			return;
		}
	}
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
		system("cls");
		cout << "pas assez de creatures" << endl;
		cout << "Retour au menu principal" << endl;
		system("pause");
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
	const vector<int> SELECTED_ID)
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
	Infliger les degat au deux creature peut importe
	s'il meurt ou pas
	En cas de double mort = match nul
	*/
	Creature* players[PLAYER_MAX] = { nullptr, nullptr };
	float input1 = 0;
	float input2 = 0;
	bool played1 = false;
	bool played2 = false;
	system("cls");
	for (int i = 0; i < SELECTED_ID.size(); i++)
		for (int j = 0; j < CREATURES.size(); j++)
			if (SELECTED_ID[i] == CREATURES[j]->m_id)
				players[i] = CREATURES[j];
	while (true) 
	{
		system("cls");
		cout << endl;
		cout << "-------------------------------" << endl;
		cout << "| The Legendary Monster Arena |" << endl;
		cout << "-------------------------------" << endl;
		cout << endl;
		cout << "[o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o]" << endl;
		cout << endl;
		for (int i = 0; i < PLAYER_MAX; i++)
		{
			cout << "FIGHTER " << i << " STATS:" << endl;
			players[i]->Print();
			cout << endl;
			cout << endl;
			cout << endl;
		}
		cout << endl;
		cout << "[o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o]" << endl;
		cout << "(W ou →) Attaque rapide : multiplicateur 0.8" << endl;
		cout << "(A ou ←) Attaque normale : multiplicateur 1.0" << endl;
		cout << "(S ou ↓) Attaque puissante : multiplicateur 1.2" << endl;
		cout << "(D ou ↑) Attaque ultime : multiplicateur 1.5" << endl;
		cout << endl;
		cout << "[o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o]" << endl;
		// INPUT1
		if (ReadKey('W') ||
			ReadKey('A') ||
			ReadKey('S') ||
			ReadKey('D'))
		{
			system("cls");
			cout << "PLAYER 1 PLAYED" << endl;
			played1 = true;
			system("pause");
		}
		if (ReadKey('W')) input1 = 0.8;
		if (ReadKey('S')) input1 = 1.0;
		if (ReadKey('A')) input1 = 1.2;
		if (ReadKey('D')) input1 = 1.5;
		
		// INPUT2
		if (ReadKey(VK_UP) ||
			ReadKey(VK_DOWN) ||
			ReadKey(VK_LEFT) ||
			ReadKey(VK_RIGHT))
		{
			system("cls");
			cout << "PLAYER 2 PLAYED" << endl;
			played2 = true;
			system("pause");
		}
		if (ReadKey(VK_UP))    input2 = 0.8;
		if (ReadKey(VK_DOWN))  input2 = 1.0;
		if (ReadKey(VK_LEFT))  input2 = 1.2;
		if (ReadKey(VK_RIGHT)) input2 = 1.5;

		Sleep(100);

		if (played1 &&
			played2)
		{
			system("cls");
			cout << "PLAYER 1 AND 2 PLAYED" << endl;
			system("pause");
			DamageCalc(
				players,
				input1,
				input2);
			input1 = 0;
		    input2 = 0;
			played1 = false;
			played2 = false;
			if (
				players[0]->m_vie <= 0 ||
				players[1]->m_vie <= 0)
			{
				return;
			}
		}
	}

}
void DamageCalc(
	Creature* const (&PLAYERS)[PLAYER_MAX],
	int INPUT1,
	int INPUT2)
{
	/*
	Les noms exacts des attaques sont 
	laiss´es `a votre discr´etion.
	Les attaques sont calcul´ees selon 
	l’´equation suivante :
	D = A * M * (100 / (100+B))
	• D repr´esente les d´egˆats inflig´es ;
	• A repr´esente la statistique d’attaque de la 
		 cr´eature attaquante ;
	• M repr´esente le multiplicateur de d´egˆats de 
		 l’attaque utilis´ee ;
	• B repr´esente la statistique de d´efense de la 
		 cr´eature cibl´ee. 
		 
	Les d´egˆats doivent ˆetre arrondis `a l’entier le plus pr`es.

	si 1 des 2 a la vie de 0 ou moins alors l'autre est marque gagnant
	En cas de double mort = match nul

	les creatures doivent demeurer dans la collection apres le combat
	*/
	float Attaque1 = 0;
	float Multi1 = 0;
	float Block1 = 0;
	float DegatSubis1 = 0;
	float Attaque2 = 0;
	float Multi2 = 0;
	float Block2 = 0;
	float DegatSubis2 = 0;

	system("cls");
	cout << "[o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o]" << endl;
	
	Attaque2 = PLAYERS[0]->m_att; // attaque player2
	Multi2 = INPUT1;             // multiplicateur player2
	Block1 = PLAYERS[1]->m_def; // defence player1

	Attaque1 = PLAYERS[1]->m_att; // attaque player2
	Multi1 = INPUT1;             // multiplicateur player2
	Block2 = PLAYERS[0]->m_def; // defence player1

	DegatSubis1 = // d´egˆats inflig´e apres calcul player1
		Attaque1 * 
		Multi1 * 
		(100/(100+Block1));

	//if (PLAYERS[0]->m_vie <= DegatSubis1)
	//	DegatSubis1 = PLAYERS[0]->m_vie;
	PLAYERS[0]->m_vie -= (int)DegatSubis1;

	cout << "PLAYER 1 CALCULATED RECEIVED DAMAGE: " << endl;
	cout << (int)DegatSubis1 << endl;

	cout << endl;
	cout << endl;
	cout << endl;

	DegatSubis2 = // d´egˆats inflig´e apres calcul player1
		Attaque2 *
		Multi2 *
		(100 / (100 + Block2));

	//if (PLAYERS[1]->m_vie <= DegatSubis2)
	//	DegatSubis2 = PLAYERS[1]->m_vie;
	PLAYERS[1]->m_vie -= (int)DegatSubis2;

	cout << "PLAYER 2 CALCULATED RECEIVED DAMAGE: " << endl;
	cout << (int)DegatSubis2 << endl;

	cout << "[o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o]" << endl;
	
	if (
		PLAYERS[0]->m_vie <= 0 &&
		PLAYERS[1]->m_vie <= 0)
	{
		system("cls");
		cout << "PLAYER 1 AND PLAYER 2 DEAD" << endl;
		cout << "DRAW" << endl;
		system("pause");
		return;
	}

	else if (PLAYERS[1]->m_vie <= 0)
	{
		system("cls");
		cout << "PLAYER 2 DEAD" << endl;
		cout << "PLAYER 1 WINS" << endl;
		system("pause");
		return;
	}
	else if (PLAYERS[0]->m_vie <= 0)
	{
		system("cls");
		cout << "PLAYER 1 DEAD" << endl;
		cout << "PLAYER 2 WINS" << endl;
		system("pause");
		return;
	}
	system("pause");
}
bool ReadKey(const int& key)
{
	return (GetAsyncKeyState(key) & 0x8000);
}
void Delete(
	const vector<Creature*>& CREATURES)
{
	cout << endl;
	cout << "deleting all objects" << endl;

	for (int i = 0; i < CREATURES.size(); i++)
		delete CREATURES[i];
}
