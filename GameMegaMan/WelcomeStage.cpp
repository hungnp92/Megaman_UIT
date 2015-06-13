#include "WelcomeStage.h"

WelcomeStage::WelcomeStage()
{
	banner = new MenuObject(MyResources::GetInstance().sBanner);
	banner->positionX = 128;
	banner->positionY = 162;

	//Set status
	banner->SetStatus(0);
	strStart = new GameString("PRESS START");
	stringTM = new GameString("TM");
	string1 = new GameString("TM AND ©1987 CAPCOM U.S.A.,INC.");
	string2 = new GameString("LICENSED BY");
	string3 = new GameString("NINTENDO OF AMERICA INC.");
	stringTM->SetPosision(132, 200);

	string1->SetTop(60);
	string1->SetCenter();
	string2->SetTop(45);
	string2->SetCenter();
	string3->SetTop(30);
	string3->SetCenter();
	strStart->SetTop(112);
	strStart->SetCenter();
}

WelcomeStage::~WelcomeStage()
{

}

void WelcomeStage::Release()
{
	if (banner != NULL)
		delete banner;
}

void WelcomeStage::Render()
{
	banner->Render();
	string1->Render();
	string2->Render();
	string3->Render();
	stringTM->Render();
	strStart->Render(isRender ? 255 : 0);
}

void WelcomeStage::Update(float _delta)
{
	banner->UpdateProcess(_delta);

	deltaTime += _delta;
	if (deltaTime >= frameTime)
	{
		isRender = !isRender;
		deltaTime = 0;
	}
}

void WelcomeStage::ProcessKeyboard()
{
	for (DWORD i = 0; i < DiMngr::GetInstance().dwElements; i++)
	{
		DWORD _keyCode = DiMngr::GetInstance().KeyEvents[i].dwOfs;
		DWORD _keyState = DiMngr::GetInstance().KeyEvents[i].dwData;

		switch (_keyCode)
		{
		case DIK_SPACE:
		case DIK_RETURN:
			if ((_keyState & 0x80) > 0)
			{
				nextStage = GameStage::STAGE_MAINMENU;
			}
			break;
		}
	}
}