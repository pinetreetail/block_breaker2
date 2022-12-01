#pragma once

#include "DxLib.h"
#include "game.h"

#include "PlayerBlock.h"
#include "TargetBlock.h"

class BouncingBall
{
public:
	BouncingBall();
	virtual ~BouncingBall();

	void init();
	void update(PlayerBlock& player, TargetBlock block);
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

