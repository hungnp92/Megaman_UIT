#include "Brick.h"


Brick::Brick() 
	:GameObj()
{
	LoadSprite(MyResources::GetInstance().sBrick);
	objectType = GameObjectType::o_BRICK;
	SetStatus(0);
	renderOrder = 2;
}


Brick::~Brick()
{
}
