#include "GameObj.h"

GameObj::GameObj()
{
	positionX = 0;
	positionY = 0;
	velocityX = 0;
	velocityY = 0;
	accelerationX = 0;
	accelerationY = 0;

	o_defAccelerationX = 0;
	o_defAccelerationY = -1500;
	o_maxVelocityX = 0;
	o_maxVelocityY = 0;
	o_damage = 0;
	o_maxHealth = 0;
	o_health = o_maxHealth;
	o_energy = 0; 
	o_bulletCount = 0;

	sprite = NULL;
	frameCount = 1;
	currentFrame = 0;	
	isAlive = true;
	renderOrder = 0;
	renderOrder = 0;
	SetFlip(false);
	SetDimension(0, 0);
	SetGradient(0, 0, 0, 0);
	RefreshBoundary();
	SetFrameRate();
}

GameObj::~GameObj()
{

}

void GameObj::LoadSprite(Sprite* _sprite)
{
	sprite = _sprite;
}

void GameObj::SetDefaultValue(float _posX, float _posY, float _width, float _height)
{
	o_defPosX = _posX;
	o_defPosY = _posY;
	o_defWidth = _width;
	o_defHeight = _height;
}

void GameObj::SetDefault()
{
	positionX = o_defPosX;
	positionY = o_defPosY;
	SetDimension(o_defWidth, o_defHeight);
	o_health = o_maxHealth;
}

void GameObj::SetFrameRate(int _frameRate)
{
	o_frameTime = (_frameRate != 0) ? (1.0f / _frameRate) : (1.0f / GAME_FRAME_RATE);
}

void GameObj::Update(float _delta)
{ 
	positionX += velocityX * _delta + _delta * _delta * accelerationX / 2;
	positionY += velocityY * _delta + _delta * _delta * accelerationY / 2;

	velocityX += accelerationX * _delta;
	velocityY += accelerationY * _delta;

	if (abs(velocityX) > o_maxVelocityX)
	{
		velocityX = velocityX / abs(velocityX) * o_maxVelocityX;
	}
}

void GameObj::UpdateProcess(float _delta)
{
	o_updateTime += _delta;
	Update(_delta);
}

void GameObj::AIControl(float _targetX, float _targetY)
{}

void GameObj::NextFrame()
{
	if (frameCount > 1)
	{
		if (o_updateTime >= o_frameTime)
		{
			currentFrame = (currentFrame + 1) % frameCount;
			o_updateTime = 0;
		}		
	}
}

void GameObj::Render(int _alpha)
{
	if (sprite != NULL)
	{
		int top = sprite->spriteStatus[objStatus].top;

		RECT srect;
		srect.left = currentFrame * width;
		srect.top = top;
		srect.right = srect.left + width;
		srect.bottom = srect.top + height;

		//Transformation matrix
		D3DXMATRIX mt;
		D3DXMatrixIdentity(&mt);
		mt._22 = -1.0f;
		mt._41 = -ViewPort::GetInstance().positionX;
		mt._42 = ViewPort::GetInstance().positionY;

		D3DXVECTOR3 position(positionX, positionY, 0);
		D3DXVECTOR4 vp_pos;
		D3DXVec3Transform(&vp_pos, &position, &mt);

		//FlipY
		D3DXVECTOR2 center_scale(vp_pos.x, vp_pos.y);

		D3DXVECTOR2 scale(flipY ? -1 : 1, 1);

		D3DXMatrixTransformation2D(&mt, &center_scale, 0, &scale, NULL, NULL, NULL);

		DxMngr::GetInstance().spriteHandler->SetTransform(&mt);

		D3DXVECTOR3 transPosition(vp_pos.x, vp_pos.y, 0.0f);

		//Render
		D3DXVECTOR3 center((float)width / 2, (float)height / 2, 0);

		DxMngr::GetInstance().spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		DxMngr::GetInstance().spriteHandler->Draw(
			sprite->texture,
			&srect,
			&center,
			&transPosition,
			D3DCOLOR_ARGB(_alpha, 255, 255, 255)
			//D3DCOLOR_XRGB(255, 255, 255)
			);
		DxMngr::GetInstance().spriteHandler->End();
	}
}

void GameObj::SetFlip(bool _flip)
{
	flipY = _flip;
}

void GameObj::SetGradient(int _top, int _bottom, int _left, int _right)
{
	gradTop = _top;
	gradBottom = _bottom;
	gradLeft = _left;
	gradRight = _right;
}

void GameObj::RefreshBoundary()
{
	oldRect = GetCurrentRect();
	oldPositionX = positionX;
	oldPositionY = positionY;
}

RECT GameObj::GetCurrentRect()
{
	RECT result;
	result.left = positionX - width / 2 + (int)width % 2;
	result.top = positionY + height / 2 + (int)height % 2;
	result.right = positionX + width / 2 + (int)width % 2;
	result.bottom = positionY - height / 2 + (int)height % 2;
	return result;
}

MY_RECT GameObj::GetOldCollisionRect()
{
	MY_RECT result;
	result.left = oldPositionX - width / 2 + gradLeft;
	result.top = oldPositionY + height / 2 + gradTop;
	result.right = oldPositionX + width / 2 + gradRight;
	result.bottom = oldPositionY - height / 2 + gradBottom;
	return result;
}

void GameObj::SetDimension(float _width, float _height)
{
	width = _width; 
	height = _height;
}

void GameObj::SetStatus(int _status)
{
	if(sprite != NULL)
	{
		objStatus = _status;
		SpriteStatus s = sprite->spriteStatus[_status];
		if (s.statusID >= 0)
		{
			SetDimension(s.frameWidth, s.frameHeight);
			frameCount = s.frameCount;
			currentFrame = 0;
		}
	}
}

bool GameObj::IsLastFrame()
{
	return currentFrame == frameCount - 1;
}

void GameObj::CollisionProcess(GameObj* _obj, float _delta, float _collisonTime, float _normalX, float _normalY)
{

}

void GameObj::Slide(GameObj* obj, float _delta, float _collisonTime, float _normalX, float _normalY)
{
	RECT rect = obj->GetCurrentRect();
	if (_normalX != 0)
	{
		if (_normalX > 0)
		{
			positionX = rect.right + (width / 2 - gradLeft) + (int)width % 2;
		}
		else
		{
			positionX = rect.left - (width / 2 + gradRight) - (int)width % 2;
		}
		velocityX = 0;
	}

	if (_normalY != 0)
	{		
		if (_normalY > 0)
		{
			positionY = rect.top + (height / 2 - gradBottom) + (int)height % 2;
		}
		else
		{
			positionY = rect.bottom - (height / 2 + gradTop) + (int)height % 2;
		}
		velocityY = 0;
	}
}

void GameObj::Deflect(GameObj* obj, float _delta, float _collisonTime, float _normalX, float _normalY)
{
	RECT rect = obj->GetCurrentRect();
	float velX = positionX - oldPositionX - (obj->positionX - obj->oldPositionX);
	float velY = positionY - oldPositionY -(obj->positionY - obj->oldPositionY);
	float remainingtime = 1.0f - _collisonTime;
	if (_normalX != 0)
	{
		float posX;
		if (_normalX > 0)
		{
			 posX = rect.right + (width / 2 - gradLeft) + (int)width % 2;
		}
		else
		{
			posX = rect.left - (width / 2 + gradRight) - (int)width % 2;
		}
		positionX = 2 * posX - positionX;
		velocityX = -velX * remainingtime / _delta;
	}
	
	if (_normalY != 0)
	{
		float posY;
		if (_normalY > 0)
		{
			posY = rect.top + (height / 2 - gradBottom) + (int)height % 2;
		}
		else
		{
			posY = rect.bottom - (height / 2 + gradTop) + (int)height % 2;
		}
		positionY = 2 * posY - positionY;
		velocityY = -velY * remainingtime / _delta;
	}
}