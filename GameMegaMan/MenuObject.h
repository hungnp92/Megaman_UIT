#pragma once
#include "StaticGameObj.h"
class MenuObject :
	public StaticGameObj
{
public:
	MenuObject(Sprite* _sprite);
	void Update(float _delta);
	~MenuObject();
};

