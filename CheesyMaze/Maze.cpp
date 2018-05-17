#include "Maze.h"

//Setting up maze

Maze::Maze()
{
}


Maze::~Maze()
{
}
//True - clear, //false - bloked
void Maze::SetMaze()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			maze[i][j] = true;
		}
	}
	maze[2][0] = maze[2][1] = maze[4][1] = maze[8][1] = maze[11][1] =
	maze[8][3] = maze[13][3] = maze[5][5] = maze[7][5] = maze[11][5] =
	maze[4][7] = maze[8][7] = maze[6][8]	= false;
	for (int i = 6; i < 10; i++) maze[i][0] = false;
	for (int i = 11; i < 14; i++) maze[i][0]= false;
	for (int i = 1; i < 7; i++) maze[i][2]  = false;
	for (int i = 10; i < 12; i++) maze[i][2]= false;
	for (int i = 13; i < 15; i++) maze[i][2]= false;
	for (int i = 0; i < 12; i++) maze[i][4] = false;
	for (int i = 13; i < 15; i++) maze[i][5] = false;
	for (int i = 1; i < 3; i++) maze[i][6]  = false;
	for (int i = 4; i < 6; i++) maze[i][6]  = false;
	for (int i = 7; i < 9; i++) maze[i][6]  = false;
	for (int i = 10; i < 12; i++) maze[i][6]= false;
	for (int i = 12; i < 14; i++) maze[i][7]= false;
	for (int i = 0; i < 2; i++) maze[i][8]	= false;
	for (int i = 3; i < 5; i++) maze[i][8]	= false;
	for (int i = 9; i < 11; i++) maze[i][8] = false;
	for (int i = 12; i < 14; i++) maze[i][8]= false;
	for (int i = 6; i < 8; i++) maze[i][9]	= false;

}