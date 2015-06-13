#pragma once
#include "BulletObj.h"
class GreenBullet :
	public BulletObj
{
public:
	GreenBullet();
	GreenBullet(GameObj* _owner);
	GreenBullet(GameObj* _owner, int _damage);
	~GreenBullet();
};