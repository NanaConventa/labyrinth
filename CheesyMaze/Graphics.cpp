#include "Graphics.h"


using namespace std; 

Graphics::Graphics()
{
	VideoMode vm(1366, 768);
}


Graphics::~Graphics()
{
}

void Graphics::SetBackground() 
{
	textureBackground.loadFromFile("graphics/background.png");
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);
	textureCheese.loadFromFile("graphics/cheese2.png");
	spriteCheese.setTexture(textureCheese);
	spriteCheese.setPosition(70, 10);
	textureIntro.loadFromFile("graphics/intro.png");
	spriteIntro.setTexture(textureIntro);
	spriteIntro.setPosition(0, 0);
	textureMouse.loadFromFile("graphics/mouse1.png");
	spriteMouse.setTexture(textureMouse);
}

void Graphics::SetMouse()
{	
	spriteMouse.setPosition(1 * 63, 9 * 63);
}
