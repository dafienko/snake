#pragma once
#include "Snake.h"
#include "Food.h"

class SnakeHead {
public:
	int x, y, xDir, yDir;

	SnakeHead() {
		SnakeHead::x = 0;
		SnakeHead::y = 0;
		SnakeHead::xDir = 0;
		SnakeHead::yDir = 0;
	}
	
	SnakeHead(int x, int y, int xDir, int yDir) {
		SnakeHead::x = x;
		SnakeHead::y = y;
		SnakeHead::xDir = xDir;
		SnakeHead::yDir = yDir;
	}

	void update();
};