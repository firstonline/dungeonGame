#include "stdafx.h"
#include "ObjectsManager.h"
#include "GameManager.h"

ObjectsManager::ObjectsManager()
{
}

ObjectsManager::~ObjectsManager()
{
	std::for_each(m_gameObjects.begin(), m_gameObjects.end(), ObjectsDeallocator());
}

void ObjectsManager::Add(std::string name, Object* gameObject)
{
	m_gameObjects.insert(std::pair<std::string, Object*>(name, gameObject));
}

void ObjectsManager::Remove(std::string name)
{
	std::map<std::string, Object*>::iterator results = m_gameObjects.find(name);
	if (results != m_gameObjects.end())
	{
		delete results->second;
		m_gameObjects.erase(results);
	}
}

Object* ObjectsManager::Get(std::string name) const
{
	std::map<std::string, Object*>::const_iterator results = m_gameObjects.find(name);
	if (results == m_gameObjects.end())
	{
		return NULL;
	}
	return results->second;

}

int ObjectsManager::GetObjectCount() const
{
	return m_gameObjects.size();
}

void ObjectsManager::DrawAll(sf::RenderWindow& renderWindow)
{
	std::map<std::string, Object*>::const_iterator itr = m_gameObjects.begin();
	while (itr != m_gameObjects.end())
	{
		itr->second->Draw(renderWindow);
		itr++;
	}
}

void ObjectsManager::UpdateAll(float ellapsedMiliseconds)
{
	std::map<std::string, Object*>::const_iterator itr = m_gameObjects.begin();

	while (itr != m_gameObjects.end())
	{
		itr->second->Update(ellapsedMiliseconds);
		itr++;
	}

}