#pragma once
#include "Sprite.h"
#include "Resources.h"
#include "DxMngr.h"
#include "ViewPort.h"

struct MY_RECT
{
public:
	float top = 0;
	float left = 0;
	float bottom = 0;
	float right = 0;
};

class GameObj
{
public:	
	GameObjectType objectType;	
	float positionX, positionY, oldPositionX, oldPositionY, width, height, accelerationX, accelerationY, velocityX, velocityY;
	RECT oldRect;

	Sprite* sprite;
	bool flipY;
	int objStatus;
	int frameCount, currentFrame;

	vector<GameObj*> buffer;
	bool isAlive;
	int renderOrder, collisionOrder;
	int gradTop, gradBottom, gradLeft, gradRight;	
	int o_damage, o_health, o_energy, o_bulletCount, o_maxHealth;

	GameObj();
	~GameObj();
	
	virtual void Update(float _delta);
	virtual void AIControl(float _targetX, float _targetY);
	virtual void Render(int _alpha = 255);
	virtual void CollisionProcess(GameObj* _obj, float _delta, float _collisonTime, float _normalX, float _normalY);

	void NextFrame();
	void UpdateProcess(float _delta);
	void LoadSprite(Sprite* _sprite);
	void SetDimension(float _width, float _height);
	void SetStatus(int _status);
	void SetFlip(bool _flip);
	void SetGradient(int _top, int _bottom, int _left, int _right);
	void RefreshBoundary();
	bool IsLastFrame();
	RECT GetCurrentRect();
	MY_RECT GetOldCollisionRect();

	void SetDefaultValue(float _posX, float _posY, float _width, float _height);
	void SetDefault();
	void SetFrameRate(int _frameRate = GAME_FRAME_RATE);
	void Slide(GameObj* obj,float _delta, float _collisonTime, float _normalX, float _normalY);
	void Deflect(GameObj* obj, float _delta, float _collisonTime, float _normalX, float _normalY);
protected:
	float o_defPosX, o_defPosY, o_defWidth, o_defHeight;
	float o_updateTime, o_frameTime;	
	float o_defAccelerationX, o_defAccelerationY, o_maxVelocityX, o_maxVelocityY;
};