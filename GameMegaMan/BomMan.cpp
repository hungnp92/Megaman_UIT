#include "BomMan.h"

BomMan::BomMan()
{
	LoadSprite(MyResources::GetInstance().sBomMan);
	objectType = GameObjectType::o_BOMMAN;
	SetStatus(BomManStatus::BomManIntro);
	SetFlip(false);
}

BomMan::~BomMan()
{
}

void BomMan::SetStatus(BomManStatus _status)
{
	status = _status;
	GameObj::SetStatus(_status);
}
