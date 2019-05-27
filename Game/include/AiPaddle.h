#pragma once
#include "Object.h"

class AiPaddle : public Object
{
public:
	AiPaddle();
	virtual ~AiPaddle();
	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

private:
	float m_velocity;  // -- left ++ right
	float m_maxVelocity;
};

