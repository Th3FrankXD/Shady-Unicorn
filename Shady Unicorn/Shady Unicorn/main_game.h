#pragma once

#include "game_state.h"

class MainGame : public TinyState
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	bool paused;
};

extern GameState coreState;