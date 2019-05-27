#include "StdAfx.h"
#include "Object.h"


Object::Object()
	: m_isLoaded(true)
{
	//_isLoaded = false;
}


Object::~Object()
{
}

void Object::Load(std::string filename)
{
	if (m_image.loadFromFile(filename) == false)
	{
		m_filename = "";
		m_isLoaded = false;
	}
	else
	{
		m_filename = filename;
		m_sprite.setTexture(m_image);
		m_isLoaded = true;
	}
}

void Object::Draw(sf::RenderWindow & renderWindow)
{
	if (m_isLoaded)
	{
		renderWindow.draw(m_sprite);
	}
}

void Object::Update(float elapsedTime)
{
}

void Object::SetPosition(float x, float y)
{
	if (m_isLoaded)
	{
		m_sprite.setPosition(x, y);
	}
}

sf::Vector2f Object::GetPosition() const
{
	if (m_isLoaded)
	{
		return m_sprite.getPosition();
	}
	return sf::Vector2f();
}

sf::Sprite& Object::GetSprite()
{
	return m_sprite;
}

bool Object::IsLoaded() const
{
	return m_isLoaded;
}

float Object::GetHeight() const
{
	return m_sprite.getGlobalBounds().height;
}

float Object::GetWidth() const
{
	return m_sprite.getGlobalBounds().width;
}

sf::Rect<float> Object::GetBoundingRect() const
{
	return m_sprite.getGlobalBounds();
}