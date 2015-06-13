#include "SuzyRed.h"

SuzyRed::SuzyRed()
{
	objectType = GameObjectType::o_SUZYRED;
	LoadSprite(MyResources::GetInstance().sSuzyRed);
	SetStatus(0);
}

SuzyRed::~SuzyRed()
{
}