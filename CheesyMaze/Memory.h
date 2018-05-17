#pragma once
#include <string.h>
#include <iostream>
#include "Moves.h"

using namespace std;

class Memory
{
public:
	Memory();
	~Memory();
	bool Positions[16][10];
	bool PositionsEver[16][10];
	Moves moveOrder[1000];
	void ClearMemory();
	int UpgMemory(int move, int PositionX, int PositionY);
	void ClearPositions();

};

