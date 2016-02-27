#pragma once

#include <vector>
#include "entity.h"
#include <SFML\Graphics.hpp>
#include <iostream>

class EntityManager
{
public:
	void Add(Entity* entity)
	{
		entities.push_back(*entity);
	}

	void Update()
	{
		int i = 0;
		for each(Entity entity in entities)
		{
			i++;
			std::cout << i;
		}
	}

	void Render(sf::RenderWindow* window)
	{
	}

	~EntityManager()
	{
	}

	std::vector<Entity> entities;
};