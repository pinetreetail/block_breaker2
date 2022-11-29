#pragma once

#include "DxLib.h"
#include "game.h"

class SceneStart
{
public:
	SceneStart();
	virtual ~SceneStart();

	void init();

	void setColor(int color) { m_color = color; }

	void update();
	void draw();

private:
	int m_color;
	bool scenedraw;

};

