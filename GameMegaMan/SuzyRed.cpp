#include "SuzyRed.h"

SuzyRed::SuzyRed() : GameObj()
{
	objectType = GameObjectType::o_SUZYRED;
	LoadSprite(MyResources::GetInstance().sSuzyRed);
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

SuzyRed::~SuzyRed()
{
}

//////////////////////////////////////////////////////////////////////////
void SuzyRed::SetStatus(SuzyStatus _status)
{
	status = _status;
	GameObj::SetStatus(_status);
	if (e_Direction)
	{
		SetGradient(0, 0, 1, -1);
	}
	else
	{
		SetGradient(-1, 1, 0, 0);
	}
}

//true - Vertical & False - Horizontal
void SuzyRed::SetDirection(bool _direction)
{
	e_Direction = _direction;
	e_PreviousMove = _direction;	//TRUE - MOVE UP & FALSE - MOVE DOWN
	velocityX = e_Direction ? 0 : o_maxVelocityX;
	velocityY = e_Direction ? o_maxVelocityY : 0;
}

//////////////////////////////////////////////////////////////////////////
//Behavior Function

//Update
void SuzyRed::Update(float _delta)
{
	//isAlive = (o_health <= 0) ? false : true;
	if (isAlive)
	{
		GameObj::Update(_delta);
		if (e_OnWall)
		{

			e_WaitTimeToFly += _delta;
		}
		else
		{
			e_WaitTimeToFly = 0;
		}

		if (!IsLastFrame())
		{
			NextFrame();
		}
		
	}
	else
	{
		//Dead
	}
}

//AIControl
void SuzyRed::AIControl(float _targetX, float _targetY)
{
	if (status == SuzyStatus::SuzyNormal && e_WaitTimeToFly >= 1.0f)
	{
		Fly(e_Direction, e_PreviousMove);
		e_PreviousMove = !e_PreviousMove;
	}
}

//Collision process
void SuzyRed::CollisionProcess(GameObj* _obj, float _delta, float _collisonTime, float _normalX, float _normalY)
{
	GameObjectType type = _obj->objectType;
	switch (type)
	{
	case o_TRANSPARENT:
		if (_collisonTime < 1 && status == SuzyStatus::SuzyAttack)
		{
			if (e_Direction)
			{
				//vertical
				if (_normalY != 0)
				{
					Slide(_obj, _delta, _collisonTime, _normalX, _normalY);
					Stop();
				}
			}
			else
			{
				//Horizontal
				if (_normalX != 0)
				{
					Slide(_obj, _delta, _collisonTime, _normalX, _normalY);
					Stop();
				}
			}
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
		if (_collisonTime < 1 && status == SuzyStatus::SuzyAttack)
		{
			if (e_Direction)
			{
				//vertical
				if (_normalY != 0 )
				{
					Slide(_obj, _delta, _collisonTime, _normalX, _normalY);
					Stop();
				}
			}
			else
			{
				//horizontal
				if (_normalX != 0)
				{
					Slide(_obj, _delta, _collisonTime, _normalX, _normalY);
					Stop();
				}
			}
		}
		break;
	case o_DOOR:
		break;
	case o_BOUNCINGMUSHROOM:
		break;
	case o_BULLET:
		if (_collisonTime < 1)
		{
			//o_health -= _obj->o_damage;
		}
		break;
	case o_BOUNCINGMUSHROOMRED:
		break;
	default:
		break;
	}
}

//Fly
//_direction value: true - vertical & false - horizontal
//_preMove value:	true --> ^|^	& false - <-- down 
void SuzyRed::Fly(bool _direction, bool _preMove)
{
	if (status != SuzyStatus::SuzyAttack)
	{
		if (_direction)
		{
			//Move Vertical
			velocityX = 0;
			velocityY = _preMove ? -o_maxVelocityY : o_maxVelocityY;
		}
		else
		{
			//Move Horizontal
			velocityX = _preMove ? o_maxVelocityX : -o_maxVelocityX;
			velocityY = 0;
			
		}
		e_OnWall = false;
		SetStatus(SuzyStatus::SuzyAttack);
	}
}

//Stop
void SuzyRed::Stop()
{
	if (status != SuzyStatus::SuzyNormal)
	{
		SetStatus(SuzyStatus::SuzyNormal);
		e_OnWall = true;
	}
}