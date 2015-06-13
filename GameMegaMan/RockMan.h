#pragma once
#include "GameObj.h"

class RockMan: public GameObj
{
public:
	RockManStatus r_status;
	int r_MaxBulletCount = 3;
	float r_waitTime; //thoi gian cho giua 2 lan ban lien tiep
	int r_bulletCount; //Dem so luong bullet cua Rockman tren man hinh	
	bool r_canClimb; //Cho phep treo thang =>Collision xu ly

	RockMan();
	~RockMan();
	void SetStatus(RockManStatus _status);
	void Update(float _delta) override;
	void CollisionProcess(GameObj* _obj, float _delta, float _collisonTime, float _normalX, float _normalY) override;

	void Jump();
	void Shoot();
	void Move();
	void Wait();
	void Injured();
};