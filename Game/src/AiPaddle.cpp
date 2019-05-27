#include "StdAfx.h"
#include "AiPaddle.h"
#include "GameManager.h"
#include "Ball.h"

AiPaddle::AiPaddle() :
	m_velocity(0),
	m_maxVelocity(600.0f)
{
	Load("images/paddle.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetBoundingRect().width / 2, GetBoundingRect().height / 2);
}


AiPaddle::~AiPaddle()
{
}

void AiPaddle::Draw(sf::RenderWindow & rw)
{
	Object::Draw(rw);
}

float AiPaddle::GetVelocity() const
{
	return m_velocity;
}

void AiPaddle::Update(float elapsedTime)
{
	const Ball* gameBall = static_cast<Ball*>
		(GameManager::GetGameObjectsManager().Get("Ball"));
	sf::Vector2f ballPosition = gameBall->GetPosition();

	if (GetPosition().x - 20 < ballPosition.x)
	{
		m_velocity += 15.0f;
	}
	else if (GetPosition().x + 20 > ballPosition.x)
	{
		m_velocity -= 10.0f;

	}
	else
	{
		m_velocity = 0.0f;
	}

	if (m_velocity > m_maxVelocity)
	{
		m_velocity = m_maxVelocity;
	}

	if (m_velocity < -m_maxVelocity)
	{
		m_velocity = -m_maxVelocity;
	}

	sf::Vector2f pos = this->GetPosition();

	if (pos.x <= GetBoundingRect().width / 2
		|| pos.x >= (GameManager::SCREEN_WIDTH - GetBoundingRect().width / 2))
	{
		m_velocity = -m_velocity; // Bounce by current velocity in opposite direction
	}

	GetSprite().move(m_velocity * elapsedTime, 0);
}