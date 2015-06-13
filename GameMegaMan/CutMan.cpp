#include "CutMan.h"

CutMan::CutMan()
{
	LoadSprite(MyResources::GetInstance().sCutMan);
	objectType = GameObjectType::o_CUTMAN;
	//Set Status
	SetStatus(CutManStatus::CutManWaitNoWepond);
	SetFlip(false);
}

CutMan::~CutMan()
{
}

void CutMan::SetStatus(CutManStatus _status)
{
	status = _status;
	GameObj::SetStatus(_status);
}
