#pragma once
#include "Creature.h"
#include <vector>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <ctime>

#define PLAYER_MAX 2

void CreaturesDefaultAdd(
	std::vector<Creature*>& CREATURES);
void MenuCreatures(
	std::vector<Creature*>& CREATURES);
void MenuAfficherCreatures(
	const std::vector<Creature*>& CREATURES);
void MenuStatsCreature(
	const std::vector<Creature*>& CREATURES);
void MenuModCreature(
	std::vector<Creature*>& CREATURES);
void MenuCreateCreature(
	std::vector<Creature*>& CREATURES);
void MenuDeleteCreature(
	std::vector<Creature*>& CREATURES);
void MenuCombat(
	const std::vector<Creature*>& CREATURES);
void Combat(
	const std::vector<Creature*>& CREATURES,
	const std::vector<int> SELECTED_ID);
void DamageCalc(
	Creature* const (&PLAYERS)[PLAYER_MAX], 
	float INPUT1, 
	float INPUT2);
bool ReadKey(const int& key);
void ClearScreen(
	short x,
	short y);
void Delete(
	const std::vector<Creature*>& CREATURES);