#pragma once

#include <iostream>
#include "Mouse1.h"
#include "Inscriptions.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();

	void start();
	bool flag;
	int numberOfFirstCompleteTry;
	int numberOfTry;
	int completeTries;
	Graphics graphics;
	string direction;
	Inscriptions inscriptions;
};

