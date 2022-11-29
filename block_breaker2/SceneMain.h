#pragma once

#include "DxLib.h"
#include "game.h"

#include "BlockPlayer.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	void init();

	void setStringColor(int color) { m_Stringcolor = color; }

	void update();
	void draw();

private:
	int m_color;
	int m_Stringcolor;
	bool scenedraw;

	BlockPlayer player;

};

