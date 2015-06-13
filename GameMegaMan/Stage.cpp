#include "Stage.h"

Stage::Stage()
{
	nextStage = GameStage::STAGE_NONE;
	ViewPort::GetInstance().SetToDefault();
	backColor = D3DCOLOR_XRGB(0, 0, 0);
}

Stage::~Stage()
{

}

void Stage::Release()
{

}

void Stage::ProcessKeyboard()
{

}

void Stage::Update(float _delta)
{

}

void Stage::Render()
{

}