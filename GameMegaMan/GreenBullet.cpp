#include "GreenBullet.h"

GreenBullet::GreenBullet()
:BulletObj(MyResources::GetInstance().bGreen)
{
}

GreenBullet::GreenBullet(GameObj* _owner)
: GreenBullet()
{
	SetOwner(_owner);
}

GreenBullet::GreenBullet(GameObj* _owner, int _damage)
: GreenBullet(_owner)
{
	SetDamage(_damage);
}

GreenBullet::~GreenBullet()
{
}
