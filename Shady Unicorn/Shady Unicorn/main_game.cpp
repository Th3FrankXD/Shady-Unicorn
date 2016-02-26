#include "main_game.h"
#include <iostream>

void MainGame::Initialize(sf::RenderWindow* window)
{
	this->paused = false;
	std::cout << "game\n";
}
void MainGame::Update(sf::RenderWindow* window)
{
	if (!paused)
	{

	}
	else
	{
	}
}
void MainGame::Render(sf::RenderWindow* window)
{
	if (!paused)
	{
	}
	else
	{

	}
}
void MainGame::Destroy(sf::RenderWindow* window)
{
}