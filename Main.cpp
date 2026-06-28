#include <iostream>
#include "Creature.h"
#include "Electrique.h"
#include "Plante.h"
#include "Feu.h"
#include "Eau.h"
#include "Main.h"

using namespace std;

int main()
{
	srand(time(nullptr));
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
		if ((input < 0 && 
			 input != -1) ||
			(input >= CREATURES.size() && 
			 input != -1))
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
		if ((input < 0 && 
			 input != -1) ||
			(input >= CREATURES.size() && 
			 input != -1))
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
		if ((input < 0  && 
			 input != -1) ||
			(input >= CREATURES.size() && 
			input != -1))
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
		cout << "le total des points distribues";
		cout << "ne peux pas depasser 100" << endl;
		cout << "donner inputVie (1 point = 5 points de vie): ";
		cin >> inputVie;
		cout << endl;
		cout << "donner inputAtt (1 point = 1 points d'attaque): ";
		cin >> inputAtt;
		cout << endl;
		cout << "donner inputDef (1 point = 1 points de defence): ";
		cin >> inputDef;
		cout << endl;

		for (int i = 0; i < (int)ECreatureType::Count; i++)
			cout << "(" << i << ") " << CREATURES[0]->PrintType(
				static_cast<ECreatureType>(i)) << endl;

		cout << "donner inputType: ";
		cin >> inputType;
		cout << endl;

		cout << endl;
		cout << "donner inputName: ";
		cin >> inputName;
		cout << endl;

		cout << "static_cast<int>(ECreatureType::Count ";
		cout << static_cast<int>(ECreatureType::Count) << endl;
		if (inputVie == 0 ||
			inputAtt == 0 ||
			inputDef == 0 ||
			inputType >= (int)ECreatureType::Count ||
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
			cout << "donner un numero valide qui n'est pas 0";
			cout << "pour die, att, def ou le type n'est pas";
			cout << "parmis les choix de types permis" << endl;
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
			cout << i << ": " << CREATURES[selectedIds[i]-1]->m_name << endl;
		cout << endl;
		for (int i = 0; i < CREATURES.size(); i++)
			cout << "(" << i << ") " << CREATURES[i]->m_name << endl;
		cout << "(-1)" << " return to menu" << endl;
		cin >> input;
		if ((input < 0 && 
			 input != -1) ||
			(input >= CREATURES.size() && 
			 input != -1))
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
		ClearScreen(0, 0);

		cout << endl;
		cout << "-------------------------------" << endl;
		cout << "| The Legendary Monster Arena |" << endl;
		cout << "-------------------------------" << endl;
		cout << endl;
		cout << "[o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o]" << endl;
		cout << endl;
		for (int i = 0; i < PLAYER_MAX; i++)
		{
			if (players[i] == nullptr)
			{
				cout << "ERROR: player " << i << " is nullptr" << endl;
				system("pause");
				return;
			}
			cout << "FIGHTER " << i << " STATS:" << endl;
			players[i]->Print();
			cout << endl;
			cout << endl;
			cout << endl;
		}

		cout << endl;
		cout << "[o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o]" << endl;
		cout << endl;
		cout << "(W) " << players[0]->m_attRapide << " : multiplicateur 0.8" << endl;
		cout << "(A) " << players[0]->m_attNormale << " : multiplicateur 1.0" << endl;
		cout << "(S) " << players[0]->m_attPuissante << " : multiplicateur 1.2" << endl;
		cout << "(D) " << players[0]->m_attUltime << " : multiplicateur 1.5" << endl;
		cout << endl;
		cout << "(→) " << players[1]->m_attRapide << " : multiplicateur 0.8" << endl;
		cout << "(←) " << players[1]->m_attNormale << " : multiplicateur 1.0" << endl;
		cout << "(↓) " << players[1]->m_attPuissante << " : multiplicateur 1.2" << endl;
		cout << "(↑) " << players[1]->m_attUltime << " : multiplicateur 1.5" << endl;
		cout << endl;
		cout << "[o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o]" << endl;
		
		// INPUT1
		if ((ReadKey('W') && !played1) ||
			(ReadKey('A') && !played1) ||
			(ReadKey('S') && !played1) ||
			(ReadKey('D') && !played1))
		{
			system("cls");
			cout << "PLAYER 1 PLAYED" << endl;
			played1 = true;
			system("pause");
		}
		if (ReadKey('W')) input1 = 0.8;
		if (ReadKey('A')) input1 = 1.0;
		if (ReadKey('S')) input1 = 1.2;
		if (ReadKey('D')) input1 = 1.5;
		
		// INPUT2
		if ((ReadKey(VK_UP)    && !played2) ||
			(ReadKey(VK_DOWN)  && !played2) ||
			(ReadKey(VK_LEFT)  && !played2) ||
			(ReadKey(VK_RIGHT) && !played2))
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
				system("pause");
				return;
			}
		}
	}
}
void DamageCalc(
	Creature* const (&PLAYERS)[PLAYER_MAX],
	float INPUT1,
	float INPUT2)
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
	float Multi1 = INPUT1;
	float Block1 = 0;
	float DegatSubis1 = 0;
	float RegenTurn1 = PLAYERS[0]->m_regenPerTurn;
	float chanceDoubleAtt1 = PLAYERS[0]->m_chanceDoubleAtt;

	float Attaque2 = 0;
	float Multi2 = INPUT2;
	float Block2 = 0;
	float DegatSubis2 = 0;
	float RegenTurn2 = PLAYERS[1]->m_regenPerTurn;
	float chanceDoubleAtt2 = PLAYERS[1]->m_chanceDoubleAtt;

	system("cls");
	cout << "[o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o]" << endl;
	
	Attaque2 = PLAYERS[0]->m_att; // attaque player2
	Multi2 = INPUT2;             // multiplicateur player2
	Block1 = PLAYERS[1]->m_def; // defence player1

	Attaque1 = PLAYERS[1]->m_att; // attaque player2
	Multi1 = INPUT1;             // multiplicateur player2
	Block2 = PLAYERS[0]->m_def; // defence player1

	DegatSubis1 = // d´egˆats inflig´e apres calcul player1
		Attaque1 * 
		Multi1 * 
		(100/(100+Block1));

	// Eau : r´eduit tous les d´egˆats re¸cus de 10%.
	if (PLAYERS[0]->m_type == ECreatureType::Eau)
		DegatSubis1 *= 0.9f;

	PLAYERS[0]->m_vie -= round(DegatSubis1);

	cout << "Attaque1: " << Attaque1 << endl;
	cout << "Multi1: " << Multi1 << endl;
	cout << "Block1: " << Block1 << endl;
	cout << "DegatSubis1: " << DegatSubis1 << endl;
	cout << "vie1: " << PLAYERS[0]->m_vie << endl;

	cout << "PLAYER 1 CALCULATED RECEIVED DAMAGE: " << endl;
	cout << round(DegatSubis1) << endl;

	cout << endl;
	cout << endl;
	cout << endl;

	DegatSubis2 = // d´egˆats inflig´e apres calcul player1
		Attaque2 *
		Multi2 *
		(100 / (100 + Block2));

	// Eau : r´eduit tous les d´egˆats re¸cus de 10%.
	if (PLAYERS[1]->m_type == ECreatureType::Eau)
		DegatSubis2 *= 0.9f;

	PLAYERS[1]->m_vie -= round(DegatSubis2);

	cout << "Attaque2: " << Attaque2 << endl;
	cout << "Multi2: " << Multi2 << endl;
	cout << "Block2: " << Block2 << endl;
	cout << "DegatSubis2: " << DegatSubis2 << endl;
	cout << "vie2: " << PLAYERS[1]->m_vie << endl;

	cout << "PLAYER 2 CALCULATED RECEIVED DAMAGE: " << endl;
	cout << round(DegatSubis2) << endl;

	cout << "[o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o][o_o]" << endl;
	system("pause");

	system("cls");
	cout << "double  attaque check" << endl;
	float randomValue1 = (float)rand() / RAND_MAX;
	float randomValue2 = (float)rand() / RAND_MAX;
	if (randomValue1 <= PLAYERS[0]->m_chanceDoubleAtt)
	{
		system("pause");
		cout << "PLAYER1 DOES A DOUBLE ATTACK" << endl;
		PLAYERS[1]->m_vie -= DegatSubis2;
		system("cls");

	}
	if (randomValue2 <= PLAYERS[1]->m_chanceDoubleAtt)
	{
		system("pause");
		cout << "PLAYER2 DOES A DOUBLE ATTACK" << endl;
		PLAYERS[0]->m_vie -= DegatSubis1;
		system("cls");
	}

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

	system("cls");
	cout << "apply regen tour" << endl;
	cout << "Player1 vie " << PLAYERS[0]->m_vie << endl;
	cout << "+ " << RegenTurn1 << endl;
	PLAYERS[0]->m_vie += PLAYERS[0]->m_vie * RegenTurn1;
	cout << "Player1 vie " << PLAYERS[0]->m_vie << endl;
	cout << endl;

	cout << "Player2 vie " << PLAYERS[1]->m_vie << endl;
	cout << "+ " << RegenTurn2 << endl;
	PLAYERS[1]->m_vie += PLAYERS[1]->m_vie * RegenTurn2;
	cout << "Player2 vie " << PLAYERS[1]->m_vie << endl;
	cout << endl;
	system("pause");
}
bool ReadKey(const int& key)
{
	return (GetAsyncKeyState(key) & 0x8000);
}
void ClearScreen(
	short x,
	short y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, pos);
}
void Delete(
	const vector<Creature*>& CREATURES)
{
	cout << endl;
	cout << "deleting all objects" << endl;

	for (int i = 0; i < CREATURES.size(); i++)
		delete CREATURES[i];
}