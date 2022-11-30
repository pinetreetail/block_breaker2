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

