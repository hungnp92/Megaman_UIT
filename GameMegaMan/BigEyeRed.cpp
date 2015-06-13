#include "BigEyeRed.h"

BigEyeRed::BigEyeRed() :GameObj()
{
	LoadSprite(MyResources::GetInstance().sBigEyeRed);
	objectType = GameObjectType::o_BIGEYERED;
	SetStatus(BigEyeStatus::BigEyeOnGround);
	renderOrder = 4;
	SetFrameRate(20);
	
	//////////////////////////////////////////////////////////////////////////
	o_defAccelerationX = 0;
	o_maxVelocityX = 90;
	o_maxVelocityY = 340;
	e_timeWaitToJump = 0.0;
	accelerationY = o_defAccelerationY;

	//////////////////////////////////////////////////////////////////////////
	o_damage = 10;		//Attact damage
	o_health = 18;		// HP
}

BigEyeRed::~BigEyeRed()
{
}

void BigEyeRed::SetStatus(BigEyeStatus _status)
{
	status = _status;
	GameObj::SetStatus(_status);
	switch (_status)
	{
	case BigEyeOnGround:
		SetGradient(-11, 0, 10, -10);
	case BigEyeOnAir:
		SetGradient(-1, 0, 10, -10);
		break;
	default:
		break;
	}
}

//////////////////////////////////////////////////////////////////////////
//Override function
void BigEyeRed::Update(float _delta)
{
	if (isAlive)
	{
		//Do something when alive
		GameObj::Update(_delta);
		
		if (status == BigEyeStatus::BigEyeOnGround)
		{
			
			e_timeWaitToJump += _delta;
		}
	}
	else
	{
		//Dead
	}
}

//AIControl
void BigEyeRed::AIControl(float _targetX, float _targetY)
{
	if (status == BigEyeStatus::BigEyeOnGround && e_timeWaitToJump >= 0.5f)
	{
		Jump(_targetX, _targetY);
		e_timeWaitToJump = 0;
	}

}

//Collision Process
void BigEyeRed::CollisionProcess(GameObj* _obj, float _delta, float _collisonTime, float _normalX, float _normalY)
{
	GameObjectType type = _obj->objectType;
	switch (type)
	{
	case o_TRANSPARENT:
		if (_collisonTime < 1.0f)
		{
			if (_normalY > 0)
			{
				Slide(_obj, _delta, _collisonTime, _normalX, _normalY);
				velocityY = 0;
				velocityX = 0;
				SetStatus(BigEyeStatus::BigEyeOnGround);
			}
			else
			{
				if (_normalY != -1)
					Deflect(_obj, _delta, _collisonTime, _normalX, _normalY);
			}
		}
		break;
	case o_LADDER:
		if (_collisonTime < 1)
		{
			if (_normalY > 1)
			{
				Slide(_obj, _delta, _collisonTime, _normalX, _normalY);
				velocityY = 0;
				velocityX = 0;
				SetStatus(BigEyeStatus::BigEyeOnGround);
			}
		}
		break;
	case o_FLAG:
		break;
	case o_BACKGROUND:
		break;
	case o_ROCKMAN:
		break;
	case o_BOMMAN:
		break;
	case o_CUTMAN:
		break;
	case o_ELECMAN:
		break;
	case o_FIREMAN:
		break;
	case o_GASTMAN:
		break;
	case o_ICEMAN:
		break;
	case o_BUNBYHELIBLUE:
		break;
	case o_BUNBYHELIGREEN:
		break;
	case o_BLASTERRED:
		break;
	case o_BLASTERORANGE:
		break;
	case o_BLASTERBLUE:
		break;
	case o_MAMBU:
		break;
	case o_GABYOALLORANGE:
		break;
	case o_GABYOALLRED:
		break;
	case o_GABYOALLBLUE:
		break;
	case o_PICKETMAN:
		break;
	case o_SNIPERJOE:
		break;
	case o_WATCHER:
		break;
	case o_PEPE:
		break;
	case o_CHANGKEY:
		break;
	case o_FOOTHOLDERGREEN:
		break;
	case o_FOOTHOLDERORANGE:
		break;
	case o_CRAZYRAZY:
		break;
	case o_CRAZYRAZYBODY:
		break;
	case o_CRAZYRAZYFOOT:
		break;
	case o_BIGEYERED:
		break;
	case o_BIGEYEBLUE:
		break;
	case o_SUZYBLUE:
		break;
	case o_SUZYRED:
		break;
	case o_SUZYORANGE:
		break;
	case o_SCREWDRIVERORANGE:
		break;
	case o_SCREWDRIVERBLUE:
		break;
	case o_SCREWDRIVERRED:
		break;
	case o_SUPERCUTTER:
		break;
	case o_KILLERBOMBORANGE:
		break;
	case o_KILLERBOMBRED:
		break;
	case o_KILLERBOMBBLUE:
		break;
	case o_METALL:
		break;
	case o_FENCE:
		break;
	case o_SUPERCUTTERPARENT:
		break;
	case o_BRICK:
		if (_collisonTime < 1.0f)
		{
			if (_normalY > 0)
			{
				Slide(_obj, _delta, _collisonTime, _normalX, _normalY);
				velocityY = 0;
				velocityX = 0;
				SetStatus(BigEyeStatus::BigEyeOnGround);
			}
			else
			{
				Deflect(_obj, _delta, _collisonTime, _normalX, _normalY);
			}
		}
		break;
	case o_DOOR:
		break;
	case o_BOUNCINGMUSHROOM:
		break;
	case o_BULLET:
		break;
	default:

		break;
	}
	
	
}

//Jump
void BigEyeRed::Jump(float _targetX, float _targetY)
{
	if (rand() % 2)
	{
		//Jump far
		velocityX = (_targetX < positionX) ? -o_maxVelocityX : o_maxVelocityX;
		velocityY = o_maxVelocityY * 2/3;
	}
	else
	{
		//Jump high
		velocityX = (_targetX < positionX) ? -(o_maxVelocityX * 1/3) : (o_maxVelocityX * 1/3);
		velocityY = o_maxVelocityY;
	}
	SetStatus(BigEyeStatus::BigEyeOnAir);
	SetFlip(velocityX < 0);
	
}