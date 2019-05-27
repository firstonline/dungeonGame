#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player();
	virtual ~Player();
	void Update(float elapsedTime) override;
	void Draw(sf::RenderWindow& rw) override;

	float GetVelocity() const;

private:
	float m_velocity;  // -- left ++ right
	float m_maxVelocity;
};

