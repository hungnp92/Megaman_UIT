#include "BlueBullet.h"

BlueBullet::BlueBullet()
	:BulletObj(MyResources::GetInstance().bBlue)
{
}

BlueBullet::BlueBullet(GameObj* _owner)
	:BlueBullet()
{
	SetOwner(_owner);
}

BlueBullet::BlueBullet(GameObj* _owner, int _damage) 
	: BlueBullet(_owner)
{
	SetDamage(_damage);
}

BlueBullet::~BlueBullet()
{
}
