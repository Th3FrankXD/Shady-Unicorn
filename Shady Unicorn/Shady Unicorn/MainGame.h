#pragma once

#include "State.h"

class MainGame : public State
{
public:
	MainGame();
	virtual ~MainGame();
	virtual void Update();
	virtual void Render();
};