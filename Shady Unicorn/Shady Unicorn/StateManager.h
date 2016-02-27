#pragma once

#include "State.h"

class StateManager
{
public:
	StateManager();
	~StateManager();
	void SetState(State* type);
	State* GetState();
	void Update();
private:
	State* state;
};