#include "stdafx.h"
#include "Player.h"

direction Player::GetDirection()
{
	if ((KeyUp | KeyW).pressed())
	{
		return UP;
	}
	else if ((KeyLeft | KeyA).pressed())
	{
		return LEFT;
	}
	else if ((KeyDown | KeyS).pressed())
	{
		return DOWN;
	}
	else if ((KeyRight | KeyD).pressed())
	{
		return RIGHT;
	}
	else
		return NONE;
}

Player::Player()
{
	pos = { 0,0 };
	speed = 200;
	moveDir = { 0,0 };
	size = PLAYER_SIZE;
	eateCount = 0;
	tex = TextureAsset(U"PLAYER");
}

Player::~Player()
{
}

bool Player::IsMyRectHit(RectF _rect)
{
	float wAB = myRect.w / 2.0 + _rect.w / 2.0;
	float hAB = myRect.h / 2.0 + _rect.h / 2.0;
	float distx = abs(myRect.center().x - _rect.center().x);
	float disty = abs(myRect.center().y - _rect.center().y);
	if (wAB > distx && hAB > disty)
		return true;
	else
		return false;
}

void Player::Update()
{
	direction d = GetDirection();
	Vec2 dirs[5] =
	{
		{0,-1}, {-1,0}, {0,1}, {1,0}, {0,0}
	};
	moveDir = dirs[d];
	pos = pos + speed * Scene::DeltaTime() * moveDir;
	pos.x = Clamp(pos.x, size / 2.0, Scene::Width() - size / 2.0);
	pos.y = Clamp(pos.y, size / 2.0, Scene::Height() - size / 2.0);
	if (eateCount >= 10)
	{
		size = size * 1.25;
		eateCount = 0;
	}
	SetMyRect(size);
}

void Player::Draw()
{
	tex.resized(size).drawAt(pos);
	myRect.drawFrame(1, 1, Palette::Red);
}
