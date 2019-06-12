#include "Food.h"
#include <random>
#include <iostream>
#include <sstream>
#include "MainWindow.h"

Food::Food(int x, int y) {
	Food::x = x;
	Food::y = y;
	Food::eaten = false;
}

void Food::update() {
	if (Food::eaten) {
		OutputDebugStringA("eaten \n");
		std::random_device rd;
		std::mt19937 rng(rd() );
		std::uniform_int_distribution<int> xPos(0, 790);
		std::uniform_int_distribution<int> yPos(0, 590);
		Food::x = xPos(rng);
		Food::y = yPos(rng);
		Food::eaten = false;
	}
}

void Food::setEaten() {
	Food::eaten = true;
}