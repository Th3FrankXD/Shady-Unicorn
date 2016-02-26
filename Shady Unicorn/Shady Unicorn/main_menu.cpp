#include "main_menu.h"
#include "main_game.h"
#include <iostream>

void MainMenu::Initialize(sf::RenderWindow* window)
{
	std::cout << "menu\n";
	coreState.setState(new MainGame);
}
void MainMenu::Update(sf::RenderWindow* window)
{
}
void MainMenu::Render(sf::RenderWindow* window)
{
}
void MainMenu::Destroy(sf::RenderWindow* window)
{
}