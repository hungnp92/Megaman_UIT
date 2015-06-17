#include "SuperCutterParent.h"


SuperCutterParent::SuperCutterParent() : GameObj()
{
	objectType = GameObjectType::o_SUPERCUTTERPARENT;
	SetStatus(0);
	e_defWaitTimeToShoot = 0.3f;
	e_WaitTimeToShoot = 0.3f;
	e_AttackRange = 1000;
}


SuperCutterParent::~SuperCutterParent()
{
}

void SuperCutterParent::Update(float _delta)
{
	e_delta = _delta;
	e_WaitTimeToShoot += e_delta;
	NextFrame();
}

void SuperCutterParent::AIControl(float _targetX, float _targetY)
{
	float dX = _targetX - positionX;		//Distance between rockman and SuperCutterParent in X-Coord

	if (e_WaitTimeToShoot >= e_defWaitTimeToShoot && dX <= e_AttackRange)
	{
		Shoot(_targetX, _targetY);
		e_WaitTimeToShoot = 0.0f;
	}
}

void SuperCutterParent::Shoot(float _targetX, float _targetY)
{
	SuperCutter* cutterBullet = new SuperCutter(this);
	cutterBullet->positionX = positionX;
	cutterBullet->positionY = positionY;
	cutterBullet->ShootTarget(_targetX, _targetY);
	buffer.push_back(cutterBullet);
}