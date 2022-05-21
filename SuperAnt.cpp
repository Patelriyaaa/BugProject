#include "SuperAnt.h"
#include "Organism.h"
using namespace std;

SuperAnt::SuperAnt(World* aWorld, int xcoord, int ycoord) : Organism(aWorld, xcoord, ycoord)
{
	death_tik = 0;
}

void SuperAnt::move()
{
	breedTicks++;
	death_tik++;

	if (world->getAt(x, y + 1) != NULL)
	{
		if (world->getAt(x, y + 1)->getType() ==  BUG)
		{
			death_tik = 0;
			delete world->getAt(x, y + 1);
			movesTo(x, y + 1);
			return;
		}
	}

	if (world->getAt(x, y - 1) != NULL)
	{
		if (world->getAt(x, y - 1)->getType() == BUG)
		{
			death_tik = 0;
			delete world->getAt(x, y - 1);
			movesTo(x, y - 1);
			return;
		}
	}

	if (world->getAt(x - 1, y) != NULL)
	{
		if (world->getAt(x - 1, y)->getType() == BUG)
		{
			death_tik = 0;
			delete world->getAt(x - 1, y);
			movesTo(x - 1, y);
			return;
		}
	}
	if (world->getAt(x + 1, y) != NULL)
	{
		if (world->getAt(x + 1, y)->getType() == BUG)
		{
			death_tik = 0;
			delete world->getAt(x + 1, y);
			movesTo(x + 1, y);
			return;
		}
	}

	Move mover = world->randomMove();
	switch (mover) {
	case UP:
		if (world->getAt(x, y + 1) == NULL && in_range(x, y + 1))
		{
			movesTo(x, y + 1);
		}
		break;
	case DOWN:
		if (world->getAt(x, y - 1) == NULL && in_range(x, y - 1))
		{
			movesTo(x, y - 1);
		}
		break;
	case LEFT:
		if (world->getAt(x - 1, y) == NULL && in_range(x - 1, y))
		{
			movesTo(x - 1, y);
		}
		break;
	case RIGHT:
		if (world->getAt(x + 1, y) == NULL && in_range(x + 1, y))
		{
			movesTo(x + 1, y);
		}
		break;
	default:
		break;
	}
}

void SuperAnt::generateOffspring(int whereX, int whereY)
{
	new SuperAnt(this->world, whereX, whereY);
	breedTicks = 0;
}

void SuperAnt::breed()
{
	if (breedTicks >= BREED_SUPERANT)
	{
		breedAtAdjacentCell();
	}

}

bool SuperAnt::isDead() const
{
	if (death_tik >= STARVE_SUPERANT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

OrganismType SuperAnt::getType() const
{
	return SUPERANT;
}

char SuperAnt::representation()const
{
	return char(235);
}

int SuperAnt::size() const
{
	return 30;
}

bool SuperAnt::in_range(int xx, int yy)
{
	return (xx >= 0) && (xx < WORLDSIZE) && (yy >= 0) && (yy < WORLDSIZE);
}
