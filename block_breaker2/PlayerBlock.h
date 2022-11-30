#pragma once

#include "DxLib.h"
#include "game.h"

class PlayerBlock
{
public:
	PlayerBlock();
	virtual ~PlayerBlock();

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

	float SpeedMax;
	float Acc;
	float CurrSpeed;

	int Color;

};

