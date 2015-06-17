#pragma once
#include "BulletObj.h"

class SuperCutter :public BulletObj
{
public:
	//////////////////////////////////////////////////////////////////////////
	float e_AngleA, e_AngleB;

	SuperCutter();
	SuperCutter::SuperCutter(GameObj* b_owner);
	SuperCutter::SuperCutter(GameObj* b_owner, int b_damage);
	~SuperCutter();

	//////////////////////////////////////////////////////////////////////////
	//Function Behavior
	void Update(float _delta) override;
	void ShootTarget(float _tarX, float _tarY);
};

