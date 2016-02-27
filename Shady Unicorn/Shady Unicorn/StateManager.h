#pragma once

#include "State.h"
#include <iostream>

class StateManager
{
public:
	StateManager();
	~StateManager();
	void SetState(State* state);
	State* GetState();
	void Update();
private:
	State* state;
};