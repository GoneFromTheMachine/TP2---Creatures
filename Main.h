#include "Creature.h"
#include <vector>
#pragma once

void CreaturesDefaultAdd(
	vector<Creature*>& CREATURES);
void MenuCreatures(
	const vector<Creature*>& CREATURES);
void MenuAfficherCreatures(
	const vector<Creature*>& CREATURES);
void MenuStatsCreature(
	const vector<Creature*>& CREATURES);
void MenuModCreature(
	const vector<Creature*>& CREATURES);
void MenuDeleteCreature(
	const vector<Creature*>& CREATURES);
void MenuCombat(
	const vector<Creature*>& CREATURES);
void Combat(
	const vector<Creature*>& CREATURES,
	const vector<int> SELECTED);
void Delete(
	const vector<Creature*>& CREATURES);