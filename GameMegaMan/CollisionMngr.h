#pragma once
#define NOMINMAX
#include "GameObj.h"
#include <limits>

class CollisionMngr
{
public:
	CollisionMngr();
	~CollisionMngr();
	
	static bool RectToRect(RECT rect1, RECT rect2);

	bool CheckAABB(MY_RECT rect1, MY_RECT rect2);
	MY_RECT GetSweptBroadphase(MY_RECT rect, float Vx, float vY);
	bool AABB(MY_RECT rect1, MY_RECT rect2, float& moveX, float& moveY);
	float SweptAABB(GameObj* obj1, GameObj* obj2, float& normalx, float& normaly); //don vi perFrame (<1)

	static CollisionMngr& GetInstance()
	{
		static CollisionMngr colMngr;
		return colMngr;
	}
};

/*
float normalx, normaly;
float collisiontime = SweptAABB(box, block, out normalx, out normaly);
box.x += box.vx * collisiontime;
box.y += box.vy * collisiontime;

if (collisiontime < 1.0f)
{
// perform response here
}

*/