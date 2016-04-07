#pragma once

#include "State.h"

class MainMenu : public State
{
public:
	virtual void Init();
	virtual ~MainMenu();
	virtual void Update();
	virtual void Render();
};