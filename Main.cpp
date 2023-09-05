# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include "Player.h"
#include "Enemy.h"

const Point SCORE_POS{ 630,30 };

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	TextureAsset::Register(U"PLAYER", U"🤩"_emoji);
	TextureAsset::Register(U"ENEMY", U"💀"_emoji);

	// 太文字のフォントを作成する | Create a bold font with MSDF method
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	Player player;
	Enemy enemy[10]{
		{Vec2{Random(0, Scene::Width()), Random(0, Scene::Height())},0,{0,0}},
		{Vec2{Random(0, Scene::Width()), Random(0, Scene::Height())},0,{0,0}},
		{Vec2{Random(0, Scene::Width()), Random(0, Scene::Height())},0,{0,0}},
		{Vec2{Random(0, Scene::Width()), Random(0, Scene::Height())},0,{0,0}},
		{Vec2{Random(0, Scene::Width()), Random(0, Scene::Height())},0,{0,0}},
		{Vec2{Random(0, Scene::Width()), Random(0, Scene::Height())},0,{0,0}},
		{Vec2{Random(0, Scene::Width()), Random(0, Scene::Height())},0,{0,0}},
		{Vec2{Random(0, Scene::Width()), Random(0, Scene::Height())},0,{0,0}},
		{Vec2{Random(0, Scene::Width()), Random(0, Scene::Height())},0,{0,0}},
		{Vec2{Random(0, Scene::Width()), Random(0, Scene::Height())},0,{0,0}}
	};


	double countDownTimer = 30.0l;
	String score;//Siv3DのString型
	String cdtime;//タイマーの文字
	int totalScore = 0;

	while (System::Update())
	{
		player.Update();
		for (int i = 0; i < 10; i++) {
			if (player.IsMyRectHit(enemy[i].GetRect())) {
				enemy[i].KillEnemy();
				player.AddEatCount();
			}
		}
		//Print << U"HIT";
		player.Draw();
		for (int i = 0; i < 10; i++) {
			enemy[i].Update();
			enemy[i].Draw();
		}
		totalScore = 0;
		for (int i = 0; i < 10; i++) {
			totalScore += enemy[i].GetKillCount();
		}
		font(U"SCORE: " + ToString(totalScore)).drawAt(SCORE_POS, Palette::Black);
		countDownTimer = countDownTimer - Scene::DeltaTime();
		cdtime = ToString((int)countDownTimer);
		if (countDownTimer <= 10)
			font(cdtime).drawAt({ 400,30 }, Palette::Red);
		else
			font(cdtime).drawAt({ 400,30 }, Palette::Black);
	}
}


