#include "OrangeBullet.h"

OrangeBullet::OrangeBullet()
:BulletObj(MyResources::GetInstance().bOrange)
{
}

OrangeBullet::OrangeBullet(GameObj* _owner)
: OrangeBullet()
{
	SetOwner(_owner);
}

OrangeBullet::OrangeBullet(GameObj* _owner, int _damage)
: OrangeBullet(_owner)
{
	SetDamage(_damage);
}

OrangeBullet::~OrangeBullet()
{
}
