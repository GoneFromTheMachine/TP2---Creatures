#include "Creature.h"
#include <vector>
#pragma once

// Gestion des cr´eatures
// Toutes les cr´eatures cr´e´ees 
// doivent ˆetre conserv´ees dans une collection.
// L’utilisateur doit pouvoir :
// • Afficher toutes les cr´eatures existantes
// • Consulter les statistiques d’une cr´eature
// • Modifier une cr´eature existante
// • Supprimer une cr´eature
// Lorsqu’une cr´eature est supprim´ee, 
// elle doit ˆetre retir´ee correctement 
// de la collection.
void MenuCreatures(const vector<Creature*>& CREATURES);

void AfficherCreatures(const vector<Creature*>& CREATURES);
void StatsCreature(const vector<Creature*>& CREATURES);
void ModCreature(const vector<Creature*>& CREATURES);
void DeleteCreature(const vector<Creature*>& CREATURES);

void Delete();