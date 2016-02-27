#pragma once

#include "State.h"

class MainMenu : public State
{
public:
	MainMenu();
	virtual ~MainMenu();
	virtual void Update();
	virtual void Render();
};