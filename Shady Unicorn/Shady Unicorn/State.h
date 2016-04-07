#pragma once

class State
{
public:
	virtual void Init();
	virtual ~State();
	virtual void Update();
	virtual void Render();
};
