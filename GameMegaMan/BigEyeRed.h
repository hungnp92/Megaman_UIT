#pragma once
#include "GameObj.h"
class BigEyeRed :public GameObj
{
public:
	//////////////////////////////////////////////////////////////////////////
	//Variable
	BigEyeStatus status;
	float e_timeWaitToJump;		//Wait time to jump

	//////////////////////////////////////////////////////////////////////////
	BigEyeRed();
	~BigEyeRed();
	
	void SetStatus(BigEyeStatus _status);

	//////////////////////////////////////////////////////////////////////////
	//Override function
	//Update
	void Update(float _delta) override;

	//AIControl
	void AIControl(float _targetX, float _targetY) override;

	//Collision Process
	void CollisionProcess(GameObj* _obj, float _delta, float _collisonTime, float _normalX, float _normalY) override;
	
	//////////////////////////////////////////////////////////////////////////
	//Behavior function
	void Jump(float _targetX, float _targetY);
};

