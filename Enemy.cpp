#include "stdafx.h"
#include "Enemy.h"

const int ENEMY_SIZE{ 64 };
const int ENEMY_RECT_SIZE{ 48 };

Enemy::Enemy()
{
	pos = { 0,0 };
	speed = 100;
	moveDir = { 0,0 };
	tex = TextureAsset(U"ENEMY");
	isAlive = true;
	isTimerON = false;
	myTimer = 1.0;
	killCount = 0;
}

Enemy::Enemy(Vec2 _pos, double _speed, Vec2 _dir)
{
	pos = _pos;
	speed = _speed;
	moveDir = _dir;
	tex = TextureAsset(U"ENEMY");
	isAlive = true;
	isTimerON = false;
	myTimer = 1.0;
	killCount = 0;
}

Enemy::~Enemy()
{
}



RectF Enemy::GetRect()
{
	return(myRect);
}

void Enemy::KillEnemy()
{
	isAlive = false;
	pos = { -100,-100 };
	killCount++;
	//どっか、ランダム位置（画面内にリスポーン）
	//できる人は1秒後にリスポーン
	isTimerON = true;
}

void Enemy::Update()
{
	SetMyRect((double)ENEMY_RECT_SIZE);
	if (isTimerON)
	{
		myTimer = myTimer - Scene::DeltaTime();
	}
	if (myTimer < 0)
	{
		isTimerON = false;
		isAlive = true;
		myTimer = 1.0;
		Vec2 p(Random(0, Scene::Width()), Random(0, Scene::Height()));
		pos = p;
	}
}

void Enemy::Draw()
{
	if (isAlive) {
		tex.resized(ENEMY_SIZE).drawAt(pos);
		//myRect.drawFrame(1, 1, Palette::Red);
	}
}

int Enemy::GetKillCount()
{
	return(killCount);
}
