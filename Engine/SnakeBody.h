#pragma once
#include "Snake.h"
#include "SnakeHead.h"

class SnakeBody {
public:
	int x, y;
	SnakeBody() {
		SnakeBody::x = 0;
		SnakeBody::y = 0;
	}
};