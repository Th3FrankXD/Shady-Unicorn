#include "MainGame.h"
#include <iostream>

void MainGame::Init()
{
	std::cout << "init game\n";
	this->paused = false;
}
MainGame::~MainGame()
{
	std::cout << "destroy game\n";
}

void MainGame::Update()
{
	if (!this->paused)
	{
	}
	else
	{
	}
}

void MainGame::Render()
{
}