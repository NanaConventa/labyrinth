#include "Memory.h"



Memory::Memory()
{

}


Memory::~Memory()
{
}

void Memory::ClearMemory()
{
	for (int i = 0; i < 100; i++)
	{
		moveOrder[i].direction = "";
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Positions[i][j] = false;
		}
	}
}
int Memory::UpgMemory(int move, int PositionX, int PositionY)
{
	int i = 0;
	int zmienna = 0;
	do
	{
		if ((moveOrder[i].PositionOnTheTableX == PositionX) && (moveOrder[i].PositionOnTheTableY == PositionY))
		{
			zmienna = i;
			if (moveOrder[i].direction == "right")
			{
				if ((PositionsEver[PositionX][PositionY - 1]) == false) moveOrder[i].direction = "up";
				else if (((PositionsEver[12][3]) == false) && (PositionX >= 12)) moveOrder[i].direction = "left";
				else moveOrder[i].direction = "down";
			}


			else if (moveOrder[i].direction == "left") moveOrder[i].direction = "down";


			else if (moveOrder[i].direction == "up")
			{
				if (PositionX > 12) moveOrder[i].direction = "left";
				else if (((PositionsEver[PositionX + 1][PositionY]) == false) && (PositionX < 6)) moveOrder[i].direction = "right";
				else if ((PositionsEver[PositionX][PositionY+1]) == false) moveOrder[i].direction = "down";
				else moveOrder[i].direction = "left";
			}


			else if (moveOrder[i].direction == "down")
			{
				moveOrder[i].direction = "right";
			}


			i++;
			for (i; i <= move+30; i++)
			{
				moveOrder[i].direction = "";
				moveOrder[i].PositionOnTheTableX = 0;
				moveOrder[i].PositionOnTheTableY = 0;
			}
		}
		i++;
	} while (i < move);
	return zmienna;
}

void Memory::ClearPositions()
{
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				Positions[i][j] = false;
				PositionsEver[i][j] = false;
			}
		}
}

