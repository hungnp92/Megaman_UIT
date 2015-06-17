#pragma once
#include "GameObj.h"
#include "SuperCutter.h"

class SuperCutterParent : public GameObj
{
public:
	//////////////////////////////////////////////////////////////////////////
	//Variable
	float e_defWaitTimeToShoot, e_WaitTimeToShoot;
	float e_delta;
	float e_AttackRange;

	//////////////////////////////////////////////////////////////////////////
	SuperCutterParent();
	~SuperCutterParent();

	//////////////////////////////////////////////////////////////////////////
	//Function Behavior
	void Update(float _delta) override;
	void AIControl(float _targetX, float _targetY) override;
	void Shoot(float _targetX, float _targetY);
};

