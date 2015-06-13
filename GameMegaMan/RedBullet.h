#pragma once
#include "BulletObj.h"
class RedBullet :
	public BulletObj
{
public:
	RedBullet();
	RedBullet(GameObj* _owner);
	RedBullet(GameObj* _owner, int _damage);
	~RedBullet();
};