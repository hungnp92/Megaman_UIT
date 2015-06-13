#include "BlasterBlue.h"

BlasterBlue::BlasterBlue() :GameObj()
{
	LoadSprite(MyResources::GetInstance().sBlasterBlue);
	objectType = GameObjectType::o_BLASTERBLUE;
	SetStatus(BlasterStatus::BlasterProtected);
	e_actionTime = 0;
	e_waitTime = 0;
	e_passTime = 0;
	e_bulletNumber = 0;
	e_smallVelY = 30;
	e_velX = 150;
	e_bigVelY = 140;
	e_attackDamage = 1;

	renderOrder = 2;
	SetFrameRate(20);
}

void BlasterBlue::SetStatus(BlasterStatus _status){
	status = _status;
	GameObj::SetStatus(_status);
}

void BlasterBlue::Update(float dt)
{
	dtime = dt;
	if (e_bulletNumber == 4){
		e_bulletNumber = 0;
		SetStatus(BlasterStatus::BlasterWaitForProtected);
	}

	if (status == BlasterStatus::BlasterShoot){
		Shoot(dt, 0.4f);
		if (e_direction){

		}
		else{

		}
	}
	else if (status == BlasterStatus::BlasterProtected){
		if (e_direction){

		}
		else{

		}
	}
	else{
		if (e_direction){
			if (status == BlasterStatus::BlasterWaitForProtected){

			}
			else{

			}
		}
		else
		{
			if (status == BlasterStatus::BlasterWaitForProtected){

			}
			else{

			}
		}
	}
	/*GameObj::Update(dt);*/
	NextFrame();
}

void BlasterBlue::Shoot(float dt, float waitTime)
{
	e_passTime += dt;
	if (e_passTime > waitTime)
	{
		float b_width = width / 2;
		BulletObj* bullet = new BlueBullet(this);
		if (!e_direction)
		{
			bullet->positionX = positionX + b_width;
			bullet->positionY = positionY;
			bullet->SetVelocity(200, 30.0f - e_bulletNumber*20.0f);
		}
		else{
			bullet->positionX = positionX - b_width;
			bullet->positionY = positionY;
			bullet->SetVelocity(200, 150.0f + e_bulletNumber*20.0f);
		}
		buffer.push_back(bullet);
		e_bulletNumber++;
		e_passTime = 0;
	}
}

void BlasterBlue::AIControl(float _targetX, float _targetY)
{
	float disRockman_Blaster = sqrt(pow(positionX - _targetX, 2) + pow(positionY - _targetY, 2));
	if (disRockman_Blaster <= DISTANCE_SHOOT){
		if (status == BlasterStatus::BlasterProtected){
			e_actionTime += dtime;
		}
		else if (status == BlasterStatus::BlasterWaitForShoot || status == BlasterStatus::BlasterWaitForProtected){
			e_waitTime += dtime;
		}

		if (e_actionTime >= 1.5f){
			e_actionTime = 0;
			SetStatus(BlasterStatus::BlasterWaitForShoot);
		}
		else if (e_waitTime >= 0.2f){
			e_waitTime = 0;
			if (status == BlasterStatus::BlasterWaitForShoot){
				SetStatus(BlasterStatus::BlasterShoot);
			}
			else{
				SetStatus(BlasterStatus::BlasterProtected);
			}
		}
	}
	else{
		SetStatus(BlasterStatus::BlasterProtected);
	}
}

void BlasterBlue::SetDirection(bool value)
{
	e_direction = value;
	SetFlip(value);
}

BlasterBlue::~BlasterBlue()
{
}