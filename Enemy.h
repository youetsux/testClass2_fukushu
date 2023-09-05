#pragma once
#include "baseChar.h"
class Enemy :
    public baseChar
{
	bool isTimerON;
	double myTimer;
	int killCount;
public:
	Enemy();
	Enemy(Vec2 _pos, double _speed, Vec2 _dir);
	~Enemy();
	RectF GetRect();
	//メンバ関数
	void KillEnemy();
	void Update();
	void Draw();
	int GetKillCount();
};

