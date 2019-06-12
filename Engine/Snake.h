#pragma once
#include "SnakeHead.h"
#include "Food.h"
#include "Vec2.h"
#include "SnakeBody.h"

class Snake {
public:
	SnakeHead head;
	SnakeBody bodies[100];
	Vec2 snakePositions[1000];

	bool dead = false;

	Snake(SnakeHead head) {
		Snake::dead = false;
		Snake::head = head;
	}

	void update();
	void updatePositions();
	void updateBodies();
	void checkForHitBodies();
	void checkForFood(Food& food);

	int getLength() {
		return Snake::length;
	}
private:
	int loop = 0;
	int length = 1;
};