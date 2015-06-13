#include "RedBullet.h"

RedBullet::RedBullet()
:BulletObj(MyResources::GetInstance().bRed)
{
}

RedBullet::RedBullet(GameObj* _owner)
: RedBullet()
{
	SetOwner(_owner);
}

RedBullet::RedBullet(GameObj* _owner, int _damage)
: RedBullet(_owner)
{
	SetDamage(_damage);
}

RedBullet::~RedBullet()
{
}
