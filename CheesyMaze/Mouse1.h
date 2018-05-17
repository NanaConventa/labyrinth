#pragma once
#include <string.h>
#include <iostream>
#include "Graphics.h"
#include "Game.h"
#include "Maze.h"
#include "TimeBar.h"
#include "Memory.h"


using namespace std;
using namespace sf;

class Mouse1
{
public:
	Mouse1();
	~Mouse1();
	int move;
	float mouse1Speed;
	float positionX;
	float positionY;
	float startingPositionX;
	float startingPositionY;
	float finishPositionX;
	float finishPositionY;
	int randomNumber;
	bool isMouseMoving;
	bool isFinishPositionRefreshed;
	bool isMouseWaiting;
	bool memorizing;
	int tablePositionX;
	int tablePositionY;
	string directionOfMousesMovement;
	string PreviousDirectionOfMouseMovement;
	string direction;
	void Move(Graphics & graphics);
	void Reset();
	void SetMouseSpeed(float x);
	bool IsClear(Maze & maze, string direction);
	Clock clock;
	Clock clock1;
	Time passedTime;
	Maze mouseMaze;
	TimeBar Mouselife;
	Memory memory;
};

