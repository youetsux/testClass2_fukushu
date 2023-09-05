#pragma once
#include "baseChar.h"

const int PLAYER_SIZE{ 64 };
const int PLAYER_RECT_SIZE{ 48 };
enum direction
{
	UP, LEFT, DOWN, RIGHT, NONE
};

class Player :
    public baseChar
{
	direction GetDirection();
	double size;
	int eateCount;
public:
	Player();
	~Player();
	bool IsMyRectHit(RectF _rect);
	void Update();
	void Draw();
	void AddEatCount() { eateCount++; }
};

