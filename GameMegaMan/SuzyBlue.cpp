#include "SuzyBlue.h"

SuzyBlue::SuzyBlue() : SuzyRed()
{
	objectType = GameObjectType::o_SUZYBLUE;
	LoadSprite(MyResources::GetInstance().sSuzyBlue);
	SetStatus(SuzyStatus::SuzyAttack);
	renderOrder = 4;
	SetFrameRate(15);

	//////////////////////////////////////////////////////////////////////////
	o_defAccelerationX = 0;
	o_defAccelerationY = 0;
	o_maxVelocityX = 100;
	o_maxVelocityY = 100;
	e_WaitTimeToFly = 0.0;
	accelerationY = o_defAccelerationY;
	e_OnWall = true;

	//////////////////////////////////////////////////////////////////////////
	o_damage = 4;
	o_health = 5;

	//////////////////////////////////////////////////////////////////////////
}

SuzyBlue::~SuzyBlue()
{
}