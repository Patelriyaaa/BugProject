#include "Bug.h"
#include "Organism.h"
#include "Bomb_bug.h"
#include "World.h"
#include<Windows.h>
using namespace std;

Bomb_bug::Bomb_bug(World* aWorld, int xcoord, int ycoord) : Organism(aWorld, xcoord, ycoord)
{
	death_tik = 5;
}

void Bomb_bug::move()
{
	death_tik--;
	if (death_tik == 0)
	{
		if (world->getAt(x, y + 1) != NULL)
		{
			delete world->getAt(x, y + 1);
			world->setAt(x, y + 1, NULL);
		}
		if (world->getAt(x, y - 1) != NULL)
		{
			delete world->getAt(x, y - 1);
			world->setAt(x, y - 1, NULL);
		}
		if (world->getAt(x + 1, y) != NULL)
		{
			delete world->getAt(x + 1, y);
			world->setAt(x + 1, y, NULL);
		}
		if (world->getAt(x - 1, y) != NULL)
		{
			delete world->getAt(x - 1, y);
			world->setAt(x - 1, y, NULL);
		}
	}
}

bool Bomb_bug::isDead() const
{
	if (death_tik <= 0)
	{
		return true;
	}
}
OrganismType Bomb_bug::getType() const
{
	return BOMB_BUG;
}


char Bomb_bug::representation()const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return 48 + death_tik;
}

int Bomb_bug::size() const
{
	return 30;
}

bool Bomb_bug::in_range(int xx, int yy)
{
	return (xx >= 0) && (xx < WORLDSIZE) && (yy >= 0) && (yy < WORLDSIZE);
}