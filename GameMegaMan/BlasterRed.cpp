#include "BlasterRed.h"

BlasterRed::BlasterRed() :BlasterBlue()
{
	LoadSprite(MyResources::GetInstance().sBlasterRed);
	objectType = GameObjectType::o_BLASTERRED;
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
}

BlasterRed::~BlasterRed()
{
}

void BlasterRed::Shoot(float dt, float waitTime)
{
	e_passTime += dt;
	if (e_passTime > waitTime)
	{
		float b_width = width / 2;
		BulletObj* bullet = new RedBullet(this);
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