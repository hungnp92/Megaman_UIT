#pragma once
#include "GameObj.h"
class BulletObj :
	public GameObj
{
public:
	BulletObj(Sprite* _sprite);
	~BulletObj();
	void Update(float _delta) override;
	void SetDamage(int _damage);
	void SetOwner(GameObj* _owner);
	void SetVelocity(float _value, float _angle);
	GameObj* b_owner;
};