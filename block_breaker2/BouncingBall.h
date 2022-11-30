#pragma once

#include "DxLib.h"
#include "game.h"

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

};

