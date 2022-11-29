#include "SceneEnd.h"

namespace
{
	int FrameNum = 60;
}

SceneEnd::SceneEnd() :
	m_color(false),
	scenedraw(false)
{
}

SceneEnd::~SceneEnd()
{
}

void SceneEnd::init()
{
	setColor(GetColor(255, 255, 255));
}

void SceneEnd::update()
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

void SceneEnd::draw()
{
	if (scenedraw)	return;
	DrawString(Game::kScreenWidth / 2, Game::kScreenHeight / 2,
		"ÉQÅ[ÉÄèIÇÌÇË", m_color);
}