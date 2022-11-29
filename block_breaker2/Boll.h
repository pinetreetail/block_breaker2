#pragma once

#include "Vec2.h"

class Ball
{
public:
	Ball();
	virtual ~Ball();

	void init();

	// データの設定
	void setPos(float x, float y);
	void setPos(Vec2 pos);

	void setSize(float x);
	void setColor(unsigned int color) { m_color = color; }
	void setFill(bool fill) { m_isFill = fill; }

	void update();
	void draw();

	// 情報の取得
	Vec2 getPos() const { return m_pos; }
	bool isDead() const { return m_isDead; }

	bool collision();

private:

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;

	// 円の半径
	float m_radius;

	float m_vecX;		// X座標
	float m_vecY;		// Y座標

	unsigned int m_color;
	bool m_isFill;
	bool m_isDead;
};