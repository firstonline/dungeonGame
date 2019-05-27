#pragma once
#include "stdafx.h"

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow & window);
	virtual void Update(float elapsedTime);

	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f GetPosition() const;
	virtual bool IsLoaded() const;

	virtual float GetWidth() const;
	virtual float GetHeight() const;

	virtual sf::Rect<float> GetBoundingRect() const;

protected:
	sf::Sprite& GetSprite();

private:
	sf::Sprite  m_sprite;
	sf::Texture m_image;
	std::string m_filename;
	bool m_isLoaded;
};

