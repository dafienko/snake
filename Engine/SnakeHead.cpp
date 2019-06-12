#include "Snake.h"
#include "SnakeHead.h"
#include "MainWindow.h"
#include "Game.h"
#include "Graphics.h"
#include "Food.h"

void SnakeHead::update() {

	SnakeHead::x += xDir;
	SnakeHead::y += yDir;
}

