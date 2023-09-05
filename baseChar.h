#pragma once
class baseChar
{
public:
	Vec2 pos;
	double speed;
	Vec2 moveDir;
	Texture tex;
	RectF myRect;//バウンディングボックス
	bool isAlive;
	void SetMyRect(double _size);
};

