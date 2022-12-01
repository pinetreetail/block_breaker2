#include "SceneMain.h"

namespace
{
	int FrameNum = 60;
}

SceneMain::SceneMain()	:
	m_color(false),
	m_Stringcolor(false),
	scenedraw(false)
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::init()
{
	player.init();
	ball.init();
	block.init();

	{
		setStringColor(GetColor(255, 255, 255));
	}
}

void SceneMain::update()
{
	player.update();

	ball.update(player, block);
	
	block.update();



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
}

void SceneMain::draw()
{
	player.draw();
	ball.draw();
	block.draw();

	{
		if (scenedraw)	return;
		DrawString(50, 50,
			"スペースキーを押したら終了", m_Stringcolor);
	}
}