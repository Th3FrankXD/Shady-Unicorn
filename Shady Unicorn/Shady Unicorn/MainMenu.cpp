#include "MainMenu.h"
#include "StateManager.h"
#include "MainGame.h"
#include <iostream>

extern StateManager stateManager;

void MainMenu::Init()
{
	std::cout << "init menu\n";
}
MainMenu::~MainMenu()
{
	std::cout << "destroy menu\n";
}

void MainMenu::Update()
{
	stateManager.SetState(new MainGame);
}

void MainMenu::Render()
{
}