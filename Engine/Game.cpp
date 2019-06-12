/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Snake.h"
#include "SnakeHead.h"
#include <random>
#include "Food.h"
#include <iostream>
#include <sstream>

SnakeHead head = SnakeHead(400, 300, 0, 0);
Snake snake = Snake(head);
Food jon = Food(400, 200);

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}



void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP) && snake.head.yDir == 0) {
		snake.head.yDir = -1;
		snake.head.xDir = 0;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN) && snake.head.yDir == 0) {
		snake.head.yDir = 1;
		snake.head.xDir = 0;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT) && snake.head.xDir == 0) {
		snake.head.xDir = 1;
		snake.head.yDir = 0;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT) && snake.head.xDir == 0) {
		snake.head.xDir = -1;
		snake.head.yDir = 0;
	}

	snake.update();
	jon.update();
	snake.checkForFood(jon);
	snake.updatePositions();
	snake.updateBodies();
	snake.checkForHitBodies();
}

void Game::ComposeFrame()
{
	if (!snake.dead) {
		drawHead(snake.head.x, snake.head.y);

		for (int i = 0; i < snake.getLength() - 1; i++) {
			drawBody(snake.bodies[i].x, snake.bodies[i].y);
		}
	}
	if (!jon.eaten) {
		drawFood(jon.x, jon.y);
	}
}

void Game::drawFood(int x, int y) {
	gfx.PutPixel(x + 0, y + 0, 255, 255, 255);
	gfx.PutPixel(x + 0, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 0, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 0, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 0, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 0, y + 5, 255, 255, 255);
	gfx.PutPixel(x + 0, y + 6, 255, 255, 255);
	gfx.PutPixel(x + 0, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 0, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 0, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 0, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 1, 179, 41, 41);
	gfx.PutPixel(x + 1, y + 2, 179, 41, 41);
	gfx.PutPixel(x + 1, y + 3, 179, 41, 41);
	gfx.PutPixel(x + 1, y + 4, 179, 41, 41);
	gfx.PutPixel(x + 1, y + 5, 179, 41, 41);
	gfx.PutPixel(x + 1, y + 6, 179, 41, 41);
	gfx.PutPixel(x + 1, y + 7, 179, 41, 41);
	gfx.PutPixel(x + 1, y + 8, 179, 41, 41);
	gfx.PutPixel(x + 1, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 0, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 1, 179, 41, 41);
	gfx.PutPixel(x + 2, y + 2, 179, 41, 41);
	gfx.PutPixel(x + 2, y + 3, 179, 41, 41);
	gfx.PutPixel(x + 2, y + 4, 179, 41, 41);
	gfx.PutPixel(x + 2, y + 5, 179, 41, 41);
	gfx.PutPixel(x + 2, y + 6, 179, 41, 41);
	gfx.PutPixel(x + 2, y + 7, 179, 41, 41);
	gfx.PutPixel(x + 2, y + 8, 179, 41, 41);
	gfx.PutPixel(x + 2, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 0, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 1, 179, 41, 41);
	gfx.PutPixel(x + 3, y + 2, 179, 41, 41);
	gfx.PutPixel(x + 3, y + 3, 179, 41, 41);
	gfx.PutPixel(x + 3, y + 4, 179, 41, 41);
	gfx.PutPixel(x + 3, y + 5, 179, 41, 41);
	gfx.PutPixel(x + 3, y + 6, 179, 41, 41);
	gfx.PutPixel(x + 3, y + 7, 179, 41, 41);
	gfx.PutPixel(x + 3, y + 8, 179, 41, 41);
	gfx.PutPixel(x + 3, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 4, y + 0, 255, 255, 255);
	gfx.PutPixel(x + 4, y + 1, 179, 41, 41);
	gfx.PutPixel(x + 4, y + 2, 179, 41, 41);
	gfx.PutPixel(x + 4, y + 3, 179, 41, 41);
	gfx.PutPixel(x + 4, y + 4, 179, 41, 41);
	gfx.PutPixel(x + 4, y + 5, 179, 41, 41);
	gfx.PutPixel(x + 4, y + 6, 179, 41, 41);
	gfx.PutPixel(x + 4, y + 7, 179, 41, 41);
	gfx.PutPixel(x + 4, y + 8, 179, 41, 41);
	gfx.PutPixel(x + 4, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 5, y + 0, 255, 255, 255);
	gfx.PutPixel(x + 5, y + 1, 179, 41, 41);
	gfx.PutPixel(x + 5, y + 2, 179, 41, 41);
	gfx.PutPixel(x + 5, y + 3, 179, 41, 41);
	gfx.PutPixel(x + 5, y + 4, 179, 41, 41);
	gfx.PutPixel(x + 5, y + 5, 179, 41, 41);
	gfx.PutPixel(x + 5, y + 6, 179, 41, 41);
	gfx.PutPixel(x + 5, y + 7, 179, 41, 41);
	gfx.PutPixel(x + 5, y + 8, 179, 41, 41);
	gfx.PutPixel(x + 5, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 0, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 1, 179, 41, 41);
	gfx.PutPixel(x + 6, y + 2, 179, 41, 41);
	gfx.PutPixel(x + 6, y + 3, 179, 41, 41);
	gfx.PutPixel(x + 6, y + 4, 179, 41, 41);
	gfx.PutPixel(x + 6, y + 5, 179, 41, 41);
	gfx.PutPixel(x + 6, y + 6, 179, 41, 41);
	gfx.PutPixel(x + 6, y + 7, 179, 41, 41);
	gfx.PutPixel(x + 6, y + 8, 179, 41, 41);
	gfx.PutPixel(x + 6, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 0, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 1, 179, 41, 41);
	gfx.PutPixel(x + 7, y + 2, 179, 41, 41);
	gfx.PutPixel(x + 7, y + 3, 179, 41, 41);
	gfx.PutPixel(x + 7, y + 4, 179, 41, 41);
	gfx.PutPixel(x + 7, y + 5, 179, 41, 41);
	gfx.PutPixel(x + 7, y + 6, 179, 41, 41);
	gfx.PutPixel(x + 7, y + 7, 179, 41, 41);
	gfx.PutPixel(x + 7, y + 8, 179, 41, 41);
	gfx.PutPixel(x + 7, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 0, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 1, 179, 41, 41);
	gfx.PutPixel(x + 8, y + 2, 179, 41, 41);
	gfx.PutPixel(x + 8, y + 3, 179, 41, 41);
	gfx.PutPixel(x + 8, y + 4, 179, 41, 41);
	gfx.PutPixel(x + 8, y + 5, 179, 41, 41);
	gfx.PutPixel(x + 8, y + 6, 179, 41, 41);
	gfx.PutPixel(x + 8, y + 7, 179, 41, 41);
	gfx.PutPixel(x + 8, y + 8, 179, 41, 41);
	gfx.PutPixel(x + 8, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 0, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 5, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 6, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 9, 255, 255, 255);

}

void Game::drawBody(int x, int y) {
	gfx.PutPixel(x + 0, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 1, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 2, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 3, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 4, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 5, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 6, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 7, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 8, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 1, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 1, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 2, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 2, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 3, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 3, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 4, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 4, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 5, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 5, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 6, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 6, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 7, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 7, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 8, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 8, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 1, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 2, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 3, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 4, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 5, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 6, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 7, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 8, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 9, 28, 28, 28);
}

void Game::drawHead(int x, int y) {
	gfx.PutPixel(x + 0, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 1, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 2, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 3, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 4, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 5, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 6, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 7, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 8, 28, 28, 28);
	gfx.PutPixel(x + 0, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 1, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 1, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 1, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 2, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 2, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 2, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 3, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 3, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 3, 28, 28, 28);
	gfx.PutPixel(x + 3, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 3, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 4, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 4, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 4, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 5, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 5, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 5, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 6, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 6, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 3, 28, 28, 28);
	gfx.PutPixel(x + 6, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 6, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 7, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 7, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 7, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 8, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 8, y + 1, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 2, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 3, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 4, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 5, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 6, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 7, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 8, 0, 255, 12);
	gfx.PutPixel(x + 8, y + 9, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 0, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 1, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 2, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 3, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 4, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 5, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 6, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 7, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 8, 28, 28, 28);
	gfx.PutPixel(x + 9, y + 9, 28, 28, 28);


}