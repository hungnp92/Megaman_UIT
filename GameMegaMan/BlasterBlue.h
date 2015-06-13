#pragma once
#include "GameObj.h"
#include "Brick.h"
#include "Math.h"

#include "BlueBullet.h"

#define DISTANCE_SHOOT 100

class BlasterBlue :public GameObj
{
protected:
	BlasterStatus status;
	float e_actionTime;//thoi gian ban
	float e_waitTime;//thoi gian cho giua 2 lan ban lien tiep
	int e_bulletNumber;//so thu tu vien dan duoc ban
	float e_passTime;//thoi gian troi qua giua 2 lan ban lien tiep
	float e_smallVelY = 45;
	float e_velX = 10;
	float e_bigVelY = 160;
	float e_attackDamage;
	bool e_direction;//huong trai phai: true-trai; false-phai
	float dtime;//day la bien truyen tu update sang AIControll de dieu khien blaster ban hay khong

public:
	// gán hướng cho blaster
	void SetDirection(bool value);
	void SetStatus(BlasterStatus _status);
	void Update(float t) override;
	void AIControl(float _targetX, float _targetY) override;
	// Thực hiện bắn đạn cho TEnemy này
	// dt: thời gian cập nhật giữa 2 frame
	// waitTime: thời gian sẽ chờ giữa 2 lần bắn
	virtual void Shoot(float dt, float waitTime);

	BlasterBlue();
	~BlasterBlue();
};

