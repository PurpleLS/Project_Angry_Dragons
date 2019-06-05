#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	m_world = new b2World(b2Vec2(0, -10));
}

void ObjectManager::Add(std::string name, GameObject* entity)
{
	std::unordered_map<std::string, GameObject*>::const_iterator found = this->entities.find(name);
	while (found != this->entities.end())
	{
		name += "0";
		found = this->entities.find(name);
	}
	this->entities.insert(std::make_pair(name, entity));
}

void ObjectManager::Add(std::string name, std::string filename, bool dynamic)
{
	std::unordered_map<std::string, GameObject*>::const_iterator found = this->entities.find(name);
	while (found != this->entities.end())
	{
		name += "0";
		found = this->entities.find(name);
	}
	GameObject* entity = new GameObject(*m_world);
	entity->Load(filename, dynamic);
	this->entities.insert(std::make_pair(name, entity));
}

ObjectManager * ObjectManager::Get(std::string name)
{
	std::unordered_map<std::string, GameObject*>::const_iterator found = this->entities.find(name);

	if (found == this->entities.end())
	{
		return NULL;
	}
	else
	{
		return found->second();
	}
}


bool ObjectManager::Update(sf::RenderWindow* window)
{
	std::vector<std::string> toRemove;

	this->m_world->Step(1.0f / 60.0f, 6, 2);

	for (auto& iterator : this->entities)
	{
		switch (iterator.second->Active())
		{
		case 0:
			toRemove.push_back(iterator.first);
			break;
		default:
			if (!iterator.second->Update(window))
			{
				return false;
			}
			break;
		}
	}

	for (auto& iterator : toRemove)
	{
		std::unordered_map<std::string, GameObject*>::const_iterator found = this->entities.find(iterator);

		if (found != this->entities.end())
		{
			delete found->second;
			this->entities.erase(iterator);
		}
	}
	toRemove.clear();

	return true;
}

void ObjectManager::Render(sf::RenderWindow* window)
{
	for (auto& iterator : this->entities)
	{
		window->draw(*iterator.second);
	}
}

ObjectManager::~ObjectManager()
{
	for (auto& iterator : this->entities)
	{
		delete iterator.second;
	}
	this->entities.clear();
	delete this->m_world;
}