#include "RockMan.h"

RockMan::RockMan()
{
	LoadSprite(MyResources::GetInstance().sRockMan);
	objectType = GameObjectType::o_ROCKMAN;
	SetStatus(RockManStatus::RockManIntro);
	SetFlip(false);

	renderOrder = 9;
	collisionOrder = 0;
	SetFrameRate(15);

	o_maxVelocityX = 100;
	o_defAccelerationX = 2500;
	o_defAccelerationY = -1500;
	accelerationY = o_defAccelerationY;
}

RockMan::~RockMan()
{
}

void RockMan::SetStatus(RockManStatus _status)
{
	r_status = _status;
	GameObj::SetStatus(_status);
	switch (_status)
	{
	case RockManIntro:
		SetGradient(-5, 5, 8, -8);
		break;
	case RockManStop:
		SetGradient(-1, 1, 3, -3);
		break;
	case RockManRun:
		SetGradient(-1, 1, 5, -5);
		break;
	case RockManRunAndShoot:
		SetGradient(-1, 1, 8, -8);
		break;
	case RockManClimb:
		SetGradient(0, 0, 3, -3);
		break;
	case RockManClimbOnTop:
		SetGradient(0, 0, 0, 0);
		break;
	case RockManFall:
		SetGradient(-3, 3, 6, -6);
		break;
	case RockManShootWhenClimb:
		SetGradient(-3, 3, 7, -7);
		break;
	case RockManShoot:
		SetGradient(-1, 1, 8, -8);
		break;
	case RockManWait:
		SetGradient(-1, 1, 3, -3);
		break;
	case RockManAfterJump:
		SetGradient(-1, 1, 6, -6);
		break;
	case RockManJump:
		SetGradient(-4, 4, 5, -5);
		break;
	}
}

void RockMan::Update(float _delta)
{
	GameObj::Update(_delta);

	NextFrame();
}

void RockMan::Jump() 
{
	
}

void RockMan::Shoot() 
{}

void RockMan::Move() {}

void RockMan::Wait() {}

void RockMan::Injured() {}

void RockMan::CollisionProcess(GameObj* _obj, float _delta, float _collisonTime, float _normalX, float _normalY)
{
	GameObjectType type = _obj->objectType;
	switch (type)
	{
	case o_TRANSPARENT:
		if (_collisonTime < 1.0f)
		{
			Slide(_obj, _delta, _collisonTime, _normalX, _normalY);
		}
		break;
	case o_LADDER:
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
			Slide(_obj, _delta, _collisonTime, _normalX, _normalY);
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