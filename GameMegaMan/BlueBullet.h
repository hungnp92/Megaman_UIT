#pragma once
#include "BulletObj.h"
class BlueBullet :
	public BulletObj
{
public:
	BlueBullet();
	BlueBullet(GameObj* _owner);
	BlueBullet(GameObj* _owner, int _damage);
	~BlueBullet();
};