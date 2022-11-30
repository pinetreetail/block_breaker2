#pragma once

#include "DxLib.h"
#include "game.h"

#include "PlayerBlock.h"

class BouncingBall
{
public:
	BouncingBall();
	virtual ~BouncingBall();

	void init();
	void update();
	void draw();

private:

	float posX;
	float posY;
	float width;

	float Speed;
	float CurrSpeedX;
	float CurrSpeedY;
	
	int Color;

	bool CurrDead;

	PlayerBlock player;

};

