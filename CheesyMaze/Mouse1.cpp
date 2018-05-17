#include "Mouse1.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include "Game.h"
#include "Maze.h"

using namespace std;
using namespace sf;

Mouse1::Mouse1()
{
	PreviousDirectionOfMouseMovement = "down";

	mouse1Speed = 400;
	startingPositionX = 63;
	startingPositionY = 9 * 63;
	positionX = 63;
	positionY = 9 * 63;
	memory.ClearMemory();
	tablePositionX = 1;
	tablePositionY = 9;
	isMouseMoving = false;
	isFinishPositionRefreshed = false;
	mouseMaze.SetMaze();
	srand((int)time(0));
	direction = "down";
	Mouselife.SetTimeBar();
	memorizing = true;
}


Mouse1::~Mouse1()
{
}

void Mouse1::SetMouseSpeed(float x)
{
	mouse1Speed = x;
}

void Mouse1::Move(Graphics & graphics)
{
	if (isMouseMoving == false)
	{
		if ((memory.Positions[tablePositionX][tablePositionY] == true) && (memorizing == true))
		{
			int n = 0;
			int zmienna;
				zmienna = memory.UpgMemory(move, tablePositionX, tablePositionY);
				if (IsClear(mouseMaze, memory.moveOrder[zmienna].direction) == false) zmienna = memory.UpgMemory(move, tablePositionX, tablePositionY);
				if (IsClear(mouseMaze, memory.moveOrder[zmienna].direction) == false) zmienna = memory.UpgMemory(move, tablePositionX, tablePositionY);
				if (IsClear(mouseMaze, memory.moveOrder[zmienna].direction) == false) zmienna = memory.UpgMemory(move, tablePositionX, tablePositionY);
				if (IsClear(mouseMaze, memory.moveOrder[zmienna].direction) == false) memory.moveOrder[zmienna].direction = "left";
				memorizing = false;
		}


		if (memory.moveOrder[move].direction == "")
		{
			randomNumber = (rand() % 3);

			if (PreviousDirectionOfMouseMovement == "down")
			{
				if ((IsClear(mouseMaze, "down") == false) && (IsClear(mouseMaze, "right") == false) && (IsClear(mouseMaze, "left") == false)) direction = "up";
				else if (randomNumber == 0) direction = "down";
				else if (randomNumber == 1) direction = "left";
				else if (randomNumber == 2) direction = "right";
			}
			else if (PreviousDirectionOfMouseMovement == "up")
			{
				if ((IsClear(mouseMaze, "up") == false) && (IsClear(mouseMaze, "right") == false) && (IsClear(mouseMaze, "left") == false)) direction = "down";
				else if (randomNumber == 0) direction = "up";
				else if (randomNumber == 1) direction = "left";
				else if (randomNumber == 2) direction = "right";
			}
			else if (PreviousDirectionOfMouseMovement == "right")
			{
				if ((IsClear(mouseMaze, "down") == false) && (IsClear(mouseMaze, "right") == false) && (IsClear(mouseMaze, "up") == false)) direction = "left";
				else if (randomNumber == 0) direction = "right";
				else if (randomNumber == 1) direction = "down";
				else if (randomNumber == 2) direction = "up";
			}
			else if (PreviousDirectionOfMouseMovement == "left")
			{
				if ((IsClear(mouseMaze, "down") == false) && (IsClear(mouseMaze, "up") == false) && (IsClear(mouseMaze, "left") == false)) direction = "right";
				else if (randomNumber == 0) direction = "left";
				else if (randomNumber == 1) direction = "down";
				else if (randomNumber == 2) direction = "up";
			}


		}

		else
		{
			direction = memory.moveOrder[move].direction;
		}

		if (IsClear(mouseMaze, direction))
		{
			isMouseMoving = true;
			if (memorizing == true)
			{
				memory.moveOrder[move].direction = direction;
				memory.moveOrder[move].PositionOnTheTableX = tablePositionX;
				memory.moveOrder[move].PositionOnTheTableY = tablePositionY;
			}
			move++;
		}
		
	}																					

	if (isMouseMoving == true)
	{
		if (direction == "left")
		{
			if (!isFinishPositionRefreshed)
			{
				isFinishPositionRefreshed = true;
				finishPositionX = (tablePositionX - 1) * 63;
			}
			Time dt = clock.restart();
			Mouselife.timeRemaining -= dt.asSeconds();
			Mouselife.timeBar.setSize(Vector2f(Mouselife.timeBarWidthPerSecond * Mouselife.timeRemaining, Mouselife.timeBarHeight));
			if (PreviousDirectionOfMouseMovement == "down") graphics.spriteMouse.rotate(90);
			else if (PreviousDirectionOfMouseMovement == "right") graphics.spriteMouse.rotate(180);
			else if (PreviousDirectionOfMouseMovement == "up") graphics.spriteMouse.rotate(270);
			PreviousDirectionOfMouseMovement = "left";

			
			
			graphics.spriteMouse.setPosition(graphics.spriteMouse.getPosition().x - (mouse1Speed * dt.asSeconds()), graphics.spriteMouse.getPosition().y);
			positionX = graphics.spriteMouse.getPosition().x;
			if (positionX <= finishPositionX)
			{
				isMouseMoving = false;
				isFinishPositionRefreshed = false;
				memory.Positions[tablePositionX][tablePositionY] = true;
				if (memorizing == true)
				memory.PositionsEver[tablePositionX][tablePositionY] = true;
				tablePositionX--;

			}
			return;
		}
		else if (direction == "right")
		{
			if (!isFinishPositionRefreshed)
			{
				isFinishPositionRefreshed = true;
				finishPositionX = (tablePositionX + 1) * 63;
			}
			Time dt = clock.restart();
			Mouselife.timeRemaining -= dt.asSeconds();
			Mouselife.timeBar.setSize(Vector2f(Mouselife.timeBarWidthPerSecond * Mouselife.timeRemaining, Mouselife.timeBarHeight));
			if (PreviousDirectionOfMouseMovement == "down") graphics.spriteMouse.rotate(270);
			else if (PreviousDirectionOfMouseMovement == "left") graphics.spriteMouse.rotate(180);
			else if (PreviousDirectionOfMouseMovement == "up") graphics.spriteMouse.rotate(90);
			PreviousDirectionOfMouseMovement = "right";
			graphics.spriteMouse.setPosition(graphics.spriteMouse.getPosition().x + (mouse1Speed * dt.asSeconds()), graphics.spriteMouse.getPosition().y);
			positionX = graphics.spriteMouse.getPosition().x;
			if (positionX >= finishPositionX)
			{
				isMouseMoving = false;
				isFinishPositionRefreshed = false;
				memory.Positions[tablePositionX][tablePositionY] = true;
				if (memorizing == true)
				memory.PositionsEver[tablePositionX][tablePositionY] = true;
				tablePositionX++;

			}
			return;
		}
		else if (direction == "up")
		{
			if (!isFinishPositionRefreshed)
			{
				isFinishPositionRefreshed = true;
				finishPositionY = (tablePositionY - 1) * 63;
			}
			Time dt = clock.restart();
			Mouselife.timeRemaining -= dt.asSeconds();
			Mouselife.timeBar.setSize(Vector2f(Mouselife.timeBarWidthPerSecond * Mouselife.timeRemaining, Mouselife.timeBarHeight));
			if (PreviousDirectionOfMouseMovement == "down") graphics.spriteMouse.rotate(180);
			else if (PreviousDirectionOfMouseMovement == "right") graphics.spriteMouse.rotate(270);
			else if (PreviousDirectionOfMouseMovement == "left") graphics.spriteMouse.rotate(90);
			PreviousDirectionOfMouseMovement = "up";

			graphics.spriteMouse.setPosition(graphics.spriteMouse.getPosition().x, graphics.spriteMouse.getPosition().y - (mouse1Speed * dt.asSeconds()));
			positionY = graphics.spriteMouse.getPosition().y;
			if (positionY <= finishPositionY)
			{
				isMouseMoving = false;
				isFinishPositionRefreshed = false;
				memory.Positions[tablePositionX][tablePositionY] = true;
				if (memorizing == true)
				memory.PositionsEver[tablePositionX][tablePositionY] = true;
				tablePositionY--;

			}

			return;
		}
		else if (direction == "down")
		{
			if (!isFinishPositionRefreshed)
			{
				isFinishPositionRefreshed = true;
				finishPositionY = (tablePositionY + 1) * 63;
			}
			Time dt = clock.restart();
			Mouselife.timeRemaining -= dt.asSeconds();
			Mouselife.timeBar.setSize(Vector2f(Mouselife.timeBarWidthPerSecond * Mouselife.timeRemaining, Mouselife.timeBarHeight));
			if (PreviousDirectionOfMouseMovement == "left") graphics.spriteMouse.rotate(270);
			else if (PreviousDirectionOfMouseMovement == "right") graphics.spriteMouse.rotate(90);
			else if (PreviousDirectionOfMouseMovement == "up") graphics.spriteMouse.rotate(180);
			PreviousDirectionOfMouseMovement = "down";

			graphics.spriteMouse.setPosition(graphics.spriteMouse.getPosition().x, graphics.spriteMouse.getPosition().y + (mouse1Speed * dt.asSeconds()));
			positionY = graphics.spriteMouse.getPosition().y;
			if (positionY >= finishPositionY)
			{
				isMouseMoving = false;
				isFinishPositionRefreshed = false;
				memory.Positions[tablePositionX][tablePositionY] = true;
				if (memorizing == true)
				memory.PositionsEver[tablePositionX][tablePositionY] = true;
				tablePositionY++;

			}
			return;
		}
	}
}

bool Mouse1::IsClear(Maze & maze, string direction)
{
	if ((direction == "down") && (tablePositionY == 9)) return false;
	else if ((direction == "right") && (tablePositionX == 14)) return false;
	else if ((direction == "up") && (tablePositionY == 0)) return false;
	else if ((direction == "left") && (tablePositionX == 0))  return false; 
	else if ((direction == "down") && (maze.maze[tablePositionX][tablePositionY + 1] == false)) return false;
	else if ((direction == "up") && (maze.maze[tablePositionX][tablePositionY - 1] == false)) return false;
	else if ((direction == "right") && (maze.maze[tablePositionX + 1][tablePositionY] == false)) return false;
	else if ((direction == "left") && (maze.maze[tablePositionX - 1][tablePositionY] == false)) return false;
	else return true;
}

void Mouse1::Reset()
{
	positionX = 63;
	positionY = 9*63;
	tablePositionX = 1;
	tablePositionY = 9;
	isMouseMoving = false;
	isFinishPositionRefreshed = false;
	Mouselife.ResetTimeBar();
	move = 0;
	memory.ClearPositions();
	memorizing = true;
	for (int i = 0; i < 20; i++)
	{
		cout << "Rozkaz #" << i << memory.moveOrder[i].direction << endl;
	}
	cout << "\n";

}