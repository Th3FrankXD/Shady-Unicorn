#include "MainMenu.h"
#include "StateManager.h"
#include "MainGame.h"

extern StateManager stateManager;

void MainMenu::Init()
{
}
MainMenu::~MainMenu()
{
}

void MainMenu::Update()
{
	stateManager.SetState(new MainGame);
}