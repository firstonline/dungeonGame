#include "stdafx.h"
#include "Player.h"
#include "GameManager.h"


Player::Player() :
	m_velocity(0),
	m_maxVelocity(600.0f)
{
	Load("images/paddle.png");
	assert(IsLoaded());
	float spriteMiddleX = GetBoundingRect().width / 2.0f;
	float spriteMiddleY = GetBoundingRect().height / 2.0f;

	GetSprite().setOrigin(spriteMiddleX, spriteMiddleY);
}


Player::~Player()
{
}

void Player::Draw(sf::RenderWindow & rw)
{
	Object::Draw(rw);
}

float Player::GetVelocity() const
{
	return m_velocity;
}

void Player::Update(float elapsedTime)
{
	if (GameManager::GetIfPressed(sf::Keyboard::Left))
	{
		std::cout << elapsedTime << std::endl;

		m_velocity -= 3.0f;
	}
	if (GameManager::GetIfPressed(sf::Keyboard::Right))
	{
		std::cout << elapsedTime << std::endl;

		m_velocity += 3.0f;
	}

	if (GameManager::GetIfPressed(sf::Keyboard::Down))
	{
		std::cout << elapsedTime << std::endl;

		m_velocity = 0.0f;
	}

	if (m_velocity > m_maxVelocity)
		m_velocity = m_maxVelocity;

	if (m_velocity < -m_maxVelocity)
		m_velocity = -m_maxVelocity;


	sf::Vector2f pos = this->GetPosition();
	int a = GetSprite().getGlobalBounds().width;
	int b = GetSprite().getGlobalBounds().left;
	float spriteMiddleX = GetSprite().getGlobalBounds().width / 2;
	if (pos.x  < spriteMiddleX
		|| pos.x > (GameManager::SCREEN_WIDTH - spriteMiddleX))
	{
		m_velocity = -m_velocity; // Bounce by current velocity in opposite direction
	}

	GetSprite().move(m_velocity * elapsedTime, 0);
}