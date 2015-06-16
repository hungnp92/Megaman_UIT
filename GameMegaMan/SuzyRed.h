#pragma once
#include "GameObj.h"
class SuzyRed :public GameObj
{
public:
	//////////////////////////////////////////////////////////////////////////
	//Variable
	SuzyStatus	status;
	float		e_WaitTimeToFly;
	bool		e_Direction;			//true - horizontal & false - vertical
	bool		e_OnWall;				//true - on wall(normal) & false - on air(attack)
	bool		e_PreviousMove;			//previous moving direction 
	float		e_delta;				//Use this delta for AIControl
	//////////////////////////////////////////////////////////////////////////
	//FUNCTION
	SuzyRed();
	~SuzyRed();

	void SetStatus(SuzyStatus _status);

	void SetDirection(bool _direction);		//Set direction to fly for Suzy

	//////////////////////////////////////////////////////////////////////////
	//Update
	void Update(float _delta) override;
	
	//AIControl
	void AIControl(float _targetX, float _targetY) override;

	//Collision process
	void CollisionProcess(GameObj* _obj, float _delta, float _collisonTime, float _normalX, float _normalY);
	
	//FlyTo
	//_direction value: true - horizontal & false - vertical
	void Fly(bool _direction, bool _preMove);

	//Stop
	void Stop();
};

