#include "Creature.h"
#include <vector>
#pragma once

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
	const vector<int> SELECTED);
void Delete(
	const vector<Creature*>& CREATURES);