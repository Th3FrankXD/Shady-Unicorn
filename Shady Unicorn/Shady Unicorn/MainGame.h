#pragma once

#include "State.h"

class MainGame : public State
{
public:
	virtual void Init();
	virtual ~MainGame();
	virtual void Update();
	virtual void Render();
private:
	bool paused;
};