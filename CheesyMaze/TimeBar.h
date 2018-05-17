#pragma once
#include <string.h>
#include <iostream>
#include "Graphics.h"


using namespace std;
using namespace sf;
class TimeBar
{
public:
	TimeBar();
	~TimeBar();
	Clock clock;
	RectangleShape timeBar;
	float timeBarStartWidth;
	float timeBarHeight;
	void SetTimeBar();
	void ResetTimeBar();
	Time gameTimeTotal;
	float timeRemaining;
	float timeBarWidthPerSecond;
};

