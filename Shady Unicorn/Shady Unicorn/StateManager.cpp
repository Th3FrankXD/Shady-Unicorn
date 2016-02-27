#include "StateManager.h"

StateManager stateManager = StateManager();

StateManager::StateManager() 
{
	this->state = nullptr;
}
StateManager::~StateManager() 
{
}

void StateManager::SetState(State* state)
{
	if (this->state != nullptr)
	{
		delete this->state;
	}
	this->state = state;
	this->state->Init();
}

State* StateManager::GetState()
{
	return this->state;
}

void StateManager::Update()
{
	this->state->Update();
}