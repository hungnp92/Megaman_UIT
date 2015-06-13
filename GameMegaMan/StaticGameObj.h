#pragma once
#include "GameObj.h"
class StaticGameObj :
	public GameObj
{
public:
	StaticGameObj();
	~StaticGameObj();
	void Render(int _alpha = 255) override;
};

