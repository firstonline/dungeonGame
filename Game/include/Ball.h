#pragma once
#include "Object.h"

class Ball : public Object
{
public:
	Ball();
	virtual ~Ball();
	void Update(float) override;

private:
	float m_velocity;
	float m_angle;
	float m_elapsedTimeSinceStart;

	float LinearVelocityX(float angle);
	float LinearVelocityY(float angle);
};

