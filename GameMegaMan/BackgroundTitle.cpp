#include "BackgroundTitle.h"

BackgroundTitle::BackgroundTitle() :GameObj()
{
	LoadSprite(MyResources::GetInstance().sBgrMap1);
	objectType = GameObjectType::o_BACKGROUND;
	SetStatus(0);
}

BackgroundTitle::BackgroundTitle(int _Id)
	:BackgroundTitle()
{
	currentFrame = _Id - 1;
}

BackgroundTitle::~BackgroundTitle()
{
}