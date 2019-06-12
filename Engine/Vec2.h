#pragma once

struct Vec2 
{
	int x, y;
	Vec2() {
		Vec2::x = 0;
		Vec2::y = 0;
	}
	Vec2(int x, int y) {
		Vec2::x = x;
		Vec2::y = y;
	}
};