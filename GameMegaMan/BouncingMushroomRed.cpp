#include "BouncingMushroomRed.h"


BouncingMushroomRed::BouncingMushroomRed() : BouncingMushroomBlue()
{
	LoadSprite(MyResources::GetInstance().sBouncingMushroomRed);
	objectType = GameObjectType::o_BOUNCINGMUSHROOM;
	SetStatus(BouncingMushroomStatus::BouncingMushroomOnGround);
	renderOrder = 4;
	SetFrameRate(20);

	//////////////////////////////////////////////////////////////////////////
	o_defAccelerationX = 0;
	o_maxVelocityX = 80;
	o_maxVelocityY = 330;
	e_timeWaitToJump = 0.0;
	accelerationY = o_defAccelerationY;
}


BouncingMushroomRed::~BouncingMushroomRed()
{
}
