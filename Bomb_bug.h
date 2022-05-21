#pragma once
#include <iostream>
#include "World.h"
#include "Organism.h"

class Bomb_bug : public Organism
{
public:

	Bomb_bug(World* aWorld, int xcoord, int ycoord);
	// In the given world moves this organism.
	void move();

	// Makes this organism breed.
	void breed() {};

	// Returns the type of this organism.
	OrganismType getType() const;

	// The character representation of this organism.
	char representation() const;

	// The size of this organism.
	int size() const;
	// Returns true if organism is dead, false otherwise.
	bool isDead() const;

	bool in_range(int xx, int yy);

private:

	void generateOffspring(int whereX, int whereY) {};
	int death_tik;
};


