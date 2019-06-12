#pragma once

class Food {
public:
	bool eaten;

	Food(int x, int y);

	void update();
	void setEaten();
	int x, y;
};