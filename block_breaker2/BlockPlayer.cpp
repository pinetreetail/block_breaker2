#include "BlockPlayer.h"

namespace
{
	constexpr float kSpeedMax = 8.0f;
	constexpr float kAcc = 0.4f;
}

BlockPlayer::BlockPlayer() :
	m_color(0),
	m_isFill(false)
{
}

BlockPlayer::~BlockPlayer()
{
}

void BlockPlayer::init()
{
	setPos(565.0f, 620.0f);
	setSize(150.0f, 20.0f);
	setColor(GetColor(255, 255, 0));
	setFill(false);
}

void BlockPlayer::setPos(float x, float y)
{
	m_pos.x = x;
	m_pos.y = y;
}

void BlockPlayer::setPos(Vec2 pos)
{
	m_pos = pos;
}

void BlockPlayer::setSize(float x, float y)
{
	m_size.x = x;
	m_size.y = y;
}

void BlockPlayer::update()
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (m_pos.x < 0) m_pos.x = 0;
	if (m_pos.x > Game::kScreenWidth - m_size.x) m_pos.x = Game::kScreenWidth - m_size.x;

	if (padState & PAD_INPUT_LEFT)
	{
		m_vec.x -= kAcc;
		if (m_vec.x < -kSpeedMax)	m_vec.x = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_vec.x += kAcc;
		if (m_vec.x > kSpeedMax)	m_vec.x = kSpeedMax;
	}
	else
	{
		m_vec.x *= 0.9f;
	}

	m_pos += m_vec;
}

void BlockPlayer::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, m_color, m_isFill);
}