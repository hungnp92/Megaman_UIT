#include "BunbyHeliGreen.h"

BunbyHeliGreen::BunbyHeliGreen() :BunbyHeliBlue()
{
	LoadSprite(MyResources::GetInstance().sBunbyHeliGreen);
	objectType = GameObjectType::o_BUNBYHELIGREEN;
	SetStatus(BunbyHeliStatus::BunbyHeliNormal);	//Set status for behavior
	renderOrder = 4;
	SetFrameRate(20);

	//////////////////////////////////////////////////////////////////////////
	o_maxVelocityX = 120;
	o_maxVelocityY = 100;
	o_defAccelerationX = 400;
	o_defAccelerationY = -1500;
	flDefaultMaxRange = 60;
	e_flAttackTime = 0;

	//////////////////////////////////////////////////////////////////////////
	o_damage = 6;
	o_health = 2;
}

BunbyHeliGreen::~BunbyHeliGreen()
{
}