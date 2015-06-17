#include "SuperCutter.h"

SuperCutter::SuperCutter() : BulletObj(MyResources::GetInstance().bSuperCutter)
{
	accelerationY = o_defAccelerationY;
	accelerationX = 0;
	SetFrameRate(10);
}

SuperCutter::SuperCutter(GameObj* b_owner) : SuperCutter()
{
	SetOwner(b_owner);
}
SuperCutter::SuperCutter(GameObj* b_owner, int b_damage) : SuperCutter(b_owner)
{
	SetDamage(b_damage);
}

SuperCutter::~SuperCutter()
{
}

//////////////////////////////////////////////////////////////////////////
void SuperCutter::Update(float _delta)
{
	BulletObj::Update(_delta);
	SetFlip(velocityX < 0);
	NextFrame();
}

void SuperCutter::ShootTarget(float _tarX, float _tarY)
{
	float dX = (_tarX - positionX) / 5;
	float dY = (_tarY - positionY) - 10;

	velocityY = sqrt(abs(dY * 2 * -o_defAccelerationY));
	velocityX = (2 * dX * abs(accelerationY)) / abs(velocityY);
}