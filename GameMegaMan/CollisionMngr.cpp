#include "CollisionMngr.h"

CollisionMngr::CollisionMngr()
{
}

CollisionMngr::~CollisionMngr()
{
}

MY_RECT CollisionMngr::GetSweptBroadphase(MY_RECT rect, float Vx, float Vy)
{
	MY_RECT result;
	result.left = Vx > 0 ? rect.left : rect.left + Vx;
	result.top = Vy > 0 ? rect.top + Vy : rect.top;
	result.right = Vx > 0 ? rect.right + Vx : rect.right;
	result.bottom = Vy > 0 ? rect.bottom : rect.bottom + Vy;
	return result;
}

bool CollisionMngr::RectToRect(RECT rect1, RECT rect2)
{
	return !(rect1.right < rect2.left || rect1.left > rect2.right || rect1.bottom > rect2.top || rect1.top < rect2.bottom);
}

bool CollisionMngr::CheckAABB(MY_RECT rect1, MY_RECT rect2)
{
	return !(rect1.right < rect2.left || rect1.left > rect2.right || rect1.bottom > rect2.top || rect1.top < rect2.bottom);
}

bool CollisionMngr::AABB(MY_RECT rect1, MY_RECT rect2, float& moveX, float& moveY)
{
	moveX = moveY = 0.0f;

	float l = rect2.left - rect1.right;
	float r = rect2.right - rect1.left;
	float t = rect2.top - rect1.bottom;
	float b = rect2.bottom - rect1.top;

	// check that there was a collision
	if (l > 0 || r < 0 || t < 0 || b > 0)
		return false;

	// find the offset of both sides
	moveX = abs(l) < r ? l : r;
	moveY = abs(t) < b ? t : b;

	// only use whichever offset is the smallest
	if (abs(moveX) < abs(moveY))
		moveY = 0.0f;
	else
		moveX = 0.0f;

	return true;
}

float CollisionMngr::SweptAABB(GameObj* obj1, GameObj* obj2, float& normalx, float& normaly)
{
	MY_RECT rec1 = obj1->GetOldCollisionRect();
	MY_RECT rec2 = obj2->GetOldCollisionRect();
	float Vx = (obj1->positionX - obj1->oldPositionX) - (obj2->positionX - obj2->oldPositionX);
	float Vy = (obj1->positionY - obj1->oldPositionY) - (obj2->positionY - obj2->oldPositionY);

	if (!CheckAABB(GetSweptBroadphase(rec1, Vx, Vy), rec2))
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}

	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// find the distance between the objects on the near and far sides for both x and y
	if (Vx > 0.0f)
	{
		xInvEntry = rec2.left - rec1.right;
		xInvExit = rec2.right - rec1.left;
	}
	else
	{
		xInvEntry = rec2.right - rec1.left;
		xInvExit = rec2.left - rec1.right;
	}

	if (Vy > 0.0f)
	{
		yInvEntry = rec2.bottom - rec1.top;
		yInvExit = rec2.top - rec1.bottom;
	}
	else
	{
		yInvEntry = rec2.top - rec1.bottom;
		yInvExit = rec2.bottom - rec1.top;
	}

	// find time of collision and time of leaving for each axis (if statement is to prevent divide by zero)
	float xEntry, yEntry;
	float xExit, yExit;

	if (Vx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / Vx;
		xExit = xInvExit / Vx;
	}

	if (Vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / Vy;
		yExit = yInvExit / Vy;
	}

	// find the earliest/latest times of collision

	if (xEntry > 1.0f)
		xEntry = std::numeric_limits<float>::max();
	if (yEntry > 1.0f)
		yEntry = std::numeric_limits<float>::max();

	float entryTime = xEntry> yEntry ? xEntry: yEntry;
	float exitTime = xExit< yExit ? xExit : yExit;

	// if there was no collision
	if (entryTime > exitTime)
	{
		normalx = 0.0f; normaly = 0.0f;	return 1.0f;
	}

	if (xEntry < 0.0f && yEntry < 0.0f) 
	{
		normalx = 0.0f; normaly = 0.0f;	return 1.0f;
	}

	if ((xEntry < 0.0f) && (rec1.right < rec2.left || rec1.left > rec2.right))
	{
		normalx = 0.0f; normaly = 0.0f;	return 1.0f;
	}

	if ((yEntry < 0.0f) && (rec1.top < rec2.bottom || rec1.bottom > rec2.top))
	{
		normalx = 0.0f; normaly = 0.0f;	return 1.0f;
	}
	// calculate normal of collided surface
	if (xEntry > yEntry)
	{
		normalx = Vx > 0 ? -1.0f : 1.0f;
		normaly = 0.0f;
	}
	else
	{
		normalx = 0.0f;
		normaly = Vy > 0 ? -1.0f : 1.0f;
	}

	// return the time of collision
	return entryTime;
}