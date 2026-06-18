#include "Creature.h"
#include <vector>
#pragma once



// Gestion des cr´eatures
// Toutes les cr´eatures cr´e´ees 
// doivent ˆetre conserv´ees dans une 
// collection.
// L’utilisateur doit pouvoir :
// • Afficher toutes les cr´eatures 
// existantes
// • Consulter les statistiques d’une 
// cr´eature
// • Modifier une cr´eature existante
// • Supprimer une cr´eature
// Lorsqu’une cr´eature est supprim´ee, 
// elle doit ˆetre retir´ee correctement 
// de la collection.
void CreaturesDefaultAdd();
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
void Delete();