#include "Game.h"


using namespace std; 
using namespace sf;


Game::Game()
{
	flag = false;
}


Game::~Game()
{
}

void Game::start()
{
	numberOfTry = 1;
	Mouse1 mouse;
	RenderWindow window(graphics.vm, "CheesyMaze!!!", Style::Fullscreen);
	//window.setFramerateLimit(60);
	graphics.SetBackground();
	graphics.SetMouse();
	inscriptions.SetFont();
	inscriptions.SetInscriptions();
	inscriptions.UpgInscriptions(numberOfTry, numberOfFirstCompleteTry, completeTries);

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		window.clear();
		if (flag == false) window.draw(graphics.spriteIntro);
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			flag = true;
			mouse.Reset();
			graphics.SetMouse();
		}
		if (flag == true)
		{
			mouse.Move(graphics);
			if (mouse.Mouselife.timeRemaining <= 0.0f)
			{
				numberOfTry++;
				mouse.Reset();
				graphics.SetMouse();
				inscriptions.UpgInscriptions(numberOfTry, numberOfFirstCompleteTry, completeTries);
			}
			if (mouse.tablePositionX == 0 && mouse.tablePositionY == 1)
			{
				completeTries++;
				if (numberOfFirstCompleteTry == 0) 
				{
					numberOfFirstCompleteTry = numberOfTry;
				}
				numberOfTry++;
				inscriptions.UpgInscriptions(numberOfTry, numberOfFirstCompleteTry, completeTries);
				mouse.Reset();
				graphics.SetMouse();
				
			}
			window.draw(graphics.spriteBackground);
	
			if (mouse.isMouseMoving == true)
			{
				if (mouse.direction == "right") graphics.spriteMouse.move(0, 52);
				if (mouse.direction == "left") graphics.spriteMouse.move(53, 0);
				if (mouse.direction == "up") graphics.spriteMouse.move(51, 59);

				window.draw(graphics.spriteMouse);
				if (mouse.direction == "right") graphics.spriteMouse.move(0, -52);
				if (mouse.direction == "left") graphics.spriteMouse.move(-53, 0);
				if (mouse.direction == "up") graphics.spriteMouse.move(-51, -59);
			}
			window.draw(mouse.Mouselife.timeBar);
			window.draw(graphics.spriteCheese);
			window.draw(inscriptions.tryMessage);
			window.draw(inscriptions.firstCompleteTryMessage);
			window.draw(inscriptions.numberOfCompleteTriesMessage);
		}
		window.display();	
		
	}
}