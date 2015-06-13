#include "BulletObj.h"

BulletObj::BulletObj(Sprite* _sprite) :GameObj()
{
	b_owner = NULL;
	objectType = GameObjectType::o_BULLET;
	LoadSprite(_sprite);
	SetStatus(0);
	SetFlip(false);

	renderOrder = 1000;
	SetFrameRate(20);
	o_maxVelocityX = 1000;
}

BulletObj::~BulletObj()
{
}

void BulletObj::Update(float _delta)
{
	GameObj::Update(_delta);
}

void BulletObj::SetVelocity(float _value, float _angle)
{
	float rad = _angle / 180 * 3.14159265359f;
	velocityX = _value * cos(rad);
	velocityY = _value * sin(rad);
}

void BulletObj:: SetDamage(int _damage)
{
	o_damage = _damage;
}

void BulletObj::SetOwner(GameObj* _owner)
{
	b_owner = _owner;
}