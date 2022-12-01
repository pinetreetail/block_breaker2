#include "BouncingBall.h"

BouncingBall::BouncingBall() :
	posX(0),
	posY(0),
	width(0),
	Color(0),
	Speed(0),
	CurrSpeedX(0),
	CurrSpeedY(0),
	CurrDead(false)
{
}

BouncingBall::~BouncingBall()
{
}

void BouncingBall::init()
{
	posX = 100;
	posY = 100;
	width = 25;

	Speed = 8;
	CurrSpeedX = Speed;
	CurrSpeedY = Speed;

	Color = GetColor(0, 255, 0);
}

void BouncingBall::update(PlayerBlock& player, TargetBlock block)
{
	if (CurrDead)	return;

	{
		if ((posX - width) < 0)
		{
			posX = width;
			CurrSpeedX = Speed;
		}
		else if (posX > Game::kScreenWidth - width)
		{
			posX = Game::kScreenWidth - width;
			CurrSpeedX = -Speed;
		}
		if ((posY - width) < 0)
		{
			posY = width;
			CurrSpeedY = Speed;
		}
		else if (posY > Game::kScreenHeight - width)
		{
			CurrDead = true;
		}
	}

	{
		if ((posY + width) > player.getTop() && posY < player.getBottom() &&
			posX > player.getLeft() && posX < player.getRight())
		{
			posY = (player.getTop() - width);
			CurrSpeedY = -Speed;
		}
	}
	
	if ((posY + width) > block.getTop() && posY < block.getBottom() &&
		posX > block.getLeft() && posX < block.getRight())
	{
		posY = (block.getTop() - width);
		CurrSpeedY = -Speed;
	}
	else if (posY < block.getTop() && (posY - width) > block.getBottom() &&
		posX > block.getLeft() && posX < block.getRight())
	{
		posY = (block.getBottom() + width);
		CurrSpeedY = Speed;
	}
	if (posY > block.getTop() && posY < block.getBottom() &&
		(posX + width) < block.getLeft())
	{
		posX = (block.getLeft() - width);
		CurrSpeedX = -Speed;
	}
	else if (posY > block.getTop() && posY < block.getBottom() &&
		(posX - width) < block.getRight())
	{
		posX = (block.getRight() + width);
		CurrSpeedX = Speed;
	}



	posX += CurrSpeedX;
	posY += CurrSpeedY;

}

void BouncingBall::draw()
{
	if (CurrDead)	return;

	DrawCircle(posX, posY, width, Color, false);
}