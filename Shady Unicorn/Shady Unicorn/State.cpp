#include "State.h"
#include <iostream>

State::State()
{
	std::cout << "enter\n";
}
State::~State()
{
	std::cout << "exit\n";
}

void State::Update()
{
}

void State::Render()
{
}