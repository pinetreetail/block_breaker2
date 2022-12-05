#include "BouncingBall.h"

BouncingBall::BouncingBall() :
	posX(0),
	posY(0),
	width(0),
	Color(0),
	Speed(0),
	CurrSpeedX(0),
	CurrSpeedY(0),
	CurrDead(true)
{
}

BouncingBall::~BouncingBall()
{
}

void BouncingBall::init()
{
	posX = Game::kScreenWidth / 2; //300
	posY = 550; //100
	width = 25;

	Speed = 8;
	CurrSpeedX = Speed;
	CurrSpeedY = Speed;

	CurrDead = false;

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
	
	{
		//　上
		if ((posY + width) > block.getTop() && (posY + width) < block.getBottom() &&
			posX > block.getLeft() && posX < block.getRight())
		{
			posY = (block.getTop() - width);
			CurrSpeedY = -Speed;
		}
		//	下
		if ((posY - width) > block.getTop() && (posY - width) < block.getBottom() &&
			posX > block.getLeft() && posX < block.getRight())
		{
			posY = (block.getBottom() + width);
			CurrSpeedY = Speed;
		}
		//　左
		if (posY < block.getTop() && posY > block.getBottom() &&
			(posX + width) > block.getLeft() && (posX + width) < block.getRight())
		{
			posX = (block.getLeft() - width);
			CurrSpeedX = -Speed;
		}
		//　右
		if (posY < block.getTop() && posY > block.getBottom() &&
			(posX - width) > block.getLeft() && (posX - width) < block.getRight())
		{
			posX = (block.getRight() + width);
			CurrSpeedX = Speed;
		}
	}

	posX += CurrSpeedX;
	posY += CurrSpeedY;

}

void BouncingBall::draw()
{
	if (CurrDead)	return;

	DrawCircle(posX, posY, width, Color, false);
}