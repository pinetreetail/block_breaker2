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
	DrawString(250, Game::kScreenHeight /2,
		"スペースキーを押したらゲームスタート", m_color);
	DrawString(300, 300,
		"ブロック崩し（未完成）", m_color);
}