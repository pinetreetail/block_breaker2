#include "SceneStart.h"

namespace
{
	int FrameNum = 60;
}

SceneStart::SceneStart()	:
	m_color(false),
	scenedraw(false)
{
}

SceneStart::~SceneStart()
{
}

void SceneStart::init()
{
	setColor(GetColor(255, 255, 255));
}

void SceneStart::update()
{
	FrameNum--;
	if (FrameNum == 0 && scenedraw == false)
	{
		FrameNum = 60;
		scenedraw = true;
	}
	else if (FrameNum == 0 && scenedraw == true)
	{
		FrameNum = 60;
		scenedraw = false;
	}
}

void SceneStart::draw()
{
	if (scenedraw)	return;
	DrawString(Game::kScreenWidth / 2, Game::kScreenHeight /2,
		"スペースキーを押したらゲームスタート", m_color);
}