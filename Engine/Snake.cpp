#include "Snake.h"
#include "SnakeBody.h"
#include "SnakeHead.h"
#include "Food.h"
#include "MainWindow.h"
#include "Vec2.h"

void Snake::updatePositions() {
	for (int i = 1000 - 1; i >= 0; i--) {
		if (i > 0) {
			Snake::snakePositions[i] = Snake::snakePositions[i - 1];
		}
		else {
			Snake::snakePositions[0] = Vec2(Snake::head.x, Snake::head.y);
		}
	}
}

void Snake::checkForHitBodies() {
	for (int i = 1; i < Snake::length - 1; i++) {
		if (Snake::head.x + 10 > Snake::bodies[i].x && Snake::head.x + 10 < Snake::bodies[i].x + 10) {
			if (Snake::head.y + 10 > Snake::bodies[i].y && Snake::head.y + 10 < Snake::bodies[i].y + 10) {
				Snake::dead = true;
			}
		}
	}
}

void Snake::updateBodies() {
	for (int i = 0; i < Snake::length - 1; i++) {
		Snake::bodies[i].x = Snake::snakePositions[10 * i + 10].x;
		Snake::bodies[i].y = Snake::snakePositions[10 * i + 10].y;
	}
}

void Snake::update() {
	if (Snake::head.x <= 0 || Snake::head.x >= 800 - 10) {
		Snake::dead = true;
		Snake::head.xDir = 0;
		Snake::head.yDir = 0;
	}
	else if (Snake::head.y <= 0 || Snake::head.y >= 600 - 10) {
		Snake::dead = true;
		Snake::head.xDir = 0;
		Snake::head.yDir = 0;
	}
	head.update();
}

void Snake::checkForFood(Food& food) {
	int x =	Snake::head.x + 5;
	int y = Snake::head.y + 5;
	int foodX = food.x;
	int foodY = food.y;
	bool alreadyEaten = food.eaten;

	if (!alreadyEaten) {
		if (x >= foodX - 5 && x <= foodX + 15) {    
			if (y >= foodY - 5 && y <= foodY + 15) {
				Snake::length += 1;
				food.eaten = true;
			}
		}
	}
}