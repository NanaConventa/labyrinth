#include "TimeBar.h"



TimeBar::TimeBar()
{
}


TimeBar::~TimeBar()
{
}

void TimeBar::SetTimeBar()
{
	timeBarStartWidth = 200;
	timeBarHeight = 40;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Yellow);
	timeBar.setPosition((1100) - timeBarStartWidth / 2, 200);
	timeRemaining = 15.0f;
	timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;
}
void TimeBar::ResetTimeBar()
{
	timeRemaining = 7.5f;
}