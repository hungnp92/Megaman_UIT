#include "BunbyHeliBlue.h"

BunbyHeliBlue::BunbyHeliBlue() :GameObj()
{
	LoadSprite(MyResources::GetInstance().sBunbyHeliBlue);
	objectType = GameObjectType::o_BUNBYHELIBLUE;
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
	o_damage = 3;
	o_health = 1;
}

BunbyHeliBlue::~BunbyHeliBlue()
{
}

void BunbyHeliBlue::SetStatus(BunbyHeliStatus _status)
{
	status = _status;
	GameObj::SetStatus(_status);
}

//////////////////////////////////////////////////////////////////////////
//Update
void BunbyHeliBlue::Update(float _delta)
{
	if (isAlive)
	{
		GameObj::Update(_delta);
		SetFlip(velocityX < 0);
		if (status == BunbyHeliStatus::BunbyHeliAttack && accelerationY * (positionY - o_defPosY) >= 0)
		{
			positionY = o_defPosY;
			velocityY = 0;
			accelerationY = 0;
			SetStatus(BunbyHeliStatus::BunbyHeliNormal);
		} 
		NextFrame();
	} 
	else
	{
		//Dead Function

	}
}

//AIControl
void BunbyHeliBlue::AIControl(float _targetX, float _targetY)
{
	if ((abs(positionX - _targetX) <= flDefaultMaxRange) && status == BunbyHeliStatus::BunbyHeliNormal)
	{
		SwingToTarget(_targetX, _targetY);
		return;
	}
	if (status == BunbyHeliStatus::BunbyHeliNormal)
	{
		Moving(positionX < _targetX);
	}
	
}
//////////////////////////////////////////////////////////////////////////
//Moving
//Value: true - right & false - left
void BunbyHeliBlue::Moving(bool _direction)
{
	if (_direction)
	{
		//Move to right
		velocityX = o_maxVelocityX;
		accelerationX = -o_defAccelerationX;
	}
	else
	{
		//Move to left
		velocityX = -o_maxVelocityX;
		accelerationX = o_defAccelerationX;
	}
}

//Swing to rockman pos - heli pos
//tarX,tarY: Rockman position
void BunbyHeliBlue::SwingToTarget(float tarX, float tarY)
{
	if (status != BunbyHeliStatus::BunbyHeliAttack)
	{
		SetStatus(BunbyHeliStatus::BunbyHeliAttack);

		accelerationX = 0;

		float dX = tarX - positionX;
		float dY = tarY - positionY;
		
		if (dY > 0)
		{
			velocityY = sqrt(abs(dY * 2 * -o_defAccelerationY));
			accelerationY = o_defAccelerationY;
			velocityX = (2 * dX * abs(accelerationY)) / abs(velocityY) ;
		}
		if (dY < 0)
		{
			velocityY = -sqrt(abs(dY * 2 * -o_defAccelerationY));
			accelerationY = -o_defAccelerationY;
			velocityX = (2 * dX * abs(accelerationY)) / abs(velocityY) ;
		}	
	}
}