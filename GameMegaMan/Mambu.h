#pragma once
#include "GameObj.h"
class Mambu :public GameObj
{
public:
	Mambu();
	~Mambu();
	void Update(float _delta) override;
};

