#include "BigEyeBlue.h"

BigEyeBlue::BigEyeBlue() :BigEyeRed()
{
	LoadSprite(MyResources::GetInstance().sBigEyeBlue);
	objectType = GameObjectType::o_BIGEYEBLUE;
	SetStatus(BigEyeStatus::BigEyeOnGround);
	renderOrder = 2;
	isAlive = true;
	SetFrameRate(20);

	//////////////////////////////////////////////////////////////////////////
	o_defAccelerationX = 0;
	o_defAccelerationY = -1000;
	o_maxVelocityX = 60;
	o_maxVelocityY = 280;
	e_timeWaitToJump = 0.0;
	accelerationY = o_defAccelerationY;

	//////////////////////////////////////////////////////////////////////////
	o_damage = 5;		//Attack damage
	o_health = 9;		//HP
}

BigEyeBlue::~BigEyeBlue()
{
}