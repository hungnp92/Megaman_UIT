#include "ElecMan.h"

ElecMan::ElecMan()
{
	LoadSprite(MyResources::GetInstance().sElecMan);
	objectType = GameObjectType::o_ELECMAN;
	SetStatus(ElecManStatus::ElecManIntro);
	SetFlip(false);
}

ElecMan::~ElecMan()
{
}

void ElecMan::SetStatus(ElecManStatus _status)
{
	status = _status;
	GameObj::SetStatus(_status);
}


