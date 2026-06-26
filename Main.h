#include "Creature.h"
#include <vector>
#pragma once
#define PLAYER_MAX 2

void CreaturesDefaultAdd(
	vector<Creature*>& CREATURES);
void MenuCreatures(
	vector<Creature*>& CREATURES);
void MenuAfficherCreatures(
	const vector<Creature*>& CREATURES);
void MenuStatsCreature(
	const vector<Creature*>& CREATURES);
void MenuModCreature(
	vector<Creature*>& CREATURES);
void MenuCreateCreature(
	vector<Creature*>& CREATURES);
void MenuDeleteCreature(
	vector<Creature*>& CREATURES);
void MenuCombat(
	const vector<Creature*>& CREATURES);
void Combat(
	const vector<Creature*>& CREATURES,
	const vector<int> SELECTED_ID);
void DamageCalc(
	Creature* const (&PLAYERS)[PLAYER_MAX], 
	float INPUT1, 
	float INPUT2);
bool ReadKey(const int& key);
void ClearScreen(
	short x,
	short y);
void Delete(
	const vector<Creature*>& CREATURES);