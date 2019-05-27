#pragma once
#include "Object.h"

class ObjectsManager
{
public:
	ObjectsManager();
	~ObjectsManager();

	void Add(std::string name, Object* gameObject);
	void Remove(std::string name);
	int GetObjectCount() const;
	Object* Get(std::string name) const;

	void DrawAll(sf::RenderWindow& renderWindow);
	void UpdateAll(float ellapsedMiliseconds);

private:
	std::map<std::string, Object*> m_gameObjects;

	struct ObjectsDeallocator
	{
		void operator()(const std::pair<std::string, Object*> & p) const
		{
			delete p.second;
		}
	};
};