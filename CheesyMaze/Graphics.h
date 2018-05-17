#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Graphics
{
public:
	Graphics();
	~Graphics();

	void SetBackground();
	void SetMouse();
	VideoMode vm;
	RenderWindow window;
	Texture textureBackground;
	Sprite spriteBackground;
	Texture textureMouse;
	Sprite spriteMouse; 
	Texture textureCheese;
	Sprite spriteCheese;
	Texture textureIntro;
	Sprite spriteIntro;
};

