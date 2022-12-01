#pragma once

#include "DxLib.h"
#include "game.h"

class TargetBlock
{
public:
	TargetBlock();
	virtual ~TargetBlock();

	void init();
	void update();
	void draw();

	float getLeft() const { return posX; }
	float getRight() const { return posX + sizeX; }
	float getTop() const { return posY; }
	float getBottom() const { return posY + sizeY; }
private:

	float posX;
	float posY;
	float sizeX;
	float sizeY;

	int Color;

	bool CurrDead;
};

