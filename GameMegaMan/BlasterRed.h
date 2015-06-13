#pragma once
#include "BlasterBlue.h"
#include "RedBullet.h"

class BlasterRed 
	: public BlasterBlue
{
public:
	BlasterRed();
	~BlasterRed();
	void Shoot(float dt, float waitTime) override;
};

