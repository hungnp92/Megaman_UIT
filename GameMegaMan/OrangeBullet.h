#pragma once
#include "BulletObj.h"
class OrangeBullet :
	public BulletObj
{
public:
	OrangeBullet();
	OrangeBullet(GameObj* _owner);
	OrangeBullet(GameObj* _owner, int _damage);
	~OrangeBullet();
};