#include "MenuStage.h"


MenuStage::MenuStage()
{
	objects.push_back(new MenuObject(MyResources::GetInstance().sboss_cutman));
	objects[0]->positionX = 95;
	objects[0]->positionY = 184;
	objects[0]->SetStatus(0);

	gameStrs.push_back(new GameString("CUTMAN"));
	//gameStrs[0]->SetPosision(160, 71);
	gameStrs[0]->SetTop(160);
	gameStrs[0]->SetCenter(objects[0]->positionX - objects[0]->width / 2, objects[0]->width);

	objects.push_back(new MenuObject(MyResources::GetInstance().sboss_gastman));
	objects[1]->positionX = 160;
	objects[1]->positionY = 184;
	objects[1]->SetStatus(0);	

	gameStrs.push_back(new GameString("GUTSMAN"));
	gameStrs[1]->SetTop(160);
	gameStrs[1]->SetCenter(objects[1]->positionX - objects[1]->width / 2, objects[1]->width);
	
	objects.push_back(new MenuObject(MyResources::GetInstance().sboss_iceman));
	objects[2]->positionX = 195;
	objects[2]->positionY = 122;
	objects[2]->SetStatus(0);

	gameStrs.push_back(new GameString("ICEMAN"));
	gameStrs[2]->SetTop(98);
	gameStrs[2]->SetCenter(objects[2]->positionX - objects[2]->width / 2, objects[2]->width);

	objects.push_back(new MenuObject(MyResources::GetInstance().sboss_bomman));
	objects[3]->positionX = 160;
	objects[3]->positionY = 60;
	objects[3]->SetStatus(0);

	gameStrs.push_back(new GameString("BOMBMAN"));
	gameStrs[3]->SetTop(36);
	gameStrs[3]->SetCenter(objects[3]->positionX - objects[3]->width / 2, objects[3]->width);

	objects.push_back(new MenuObject(MyResources::GetInstance().sboss_fireman));
	objects[4]->positionX = 95;
	objects[4]->positionY = 60;
	objects[4]->SetStatus(0);

	gameStrs.push_back(new GameString("FIREMAN"));
	gameStrs[4]->SetTop(36);
	gameStrs[4]->SetCenter(objects[4]->positionX - objects[4]->width / 2, objects[4]->width);

	objects.push_back(new MenuObject(MyResources::GetInstance().sboss_elecman));
	objects[5]->positionX = 60;
	objects[5]->positionY = 122;
	objects[5]->SetStatus(0);

	gameStrs.push_back(new GameString("ELECMAN"));
	gameStrs[5]->SetTop(98);
	gameStrs[5]->SetCenter(objects[5]->positionX - objects[5]->width / 2, objects[5]->width);

	choose = new MenuObject(MyResources::GetInstance().schoose);
	choose->SetStatus(0);
	chosen = 0;
	gameStrs2.push_back(new GameString("SELECT"));
	gameStrs2[0]->SetTop(140);
	gameStrs2[0]->SetCenter();

	gameStrs2.push_back(new GameString("STAGE"));
	gameStrs2[1]->SetTop(130);
	gameStrs2[1]->SetCenter();

	gameStrs2.push_back(new GameString("PRESS"));
	gameStrs2[2]->SetTop(115);
	gameStrs2[2]->SetCenter();

	gameStrs2.push_back(new GameString("START"));
	gameStrs2[3]->SetTop(105);
	gameStrs2[3]->SetCenter();

	backColor = D3DCOLOR_XRGB(64, 96, 248);
}


MenuStage::~MenuStage()
{

}

void MenuStage::Release()
{
	
}

void MenuStage::Render()
{
	for each (GameObj* obj in objects)
	{
		obj->Render();
	}
	choose->Render();

	for (int i = 0; i < gameStrs.size(); i++)
	{
		gameStrs[i]->Render(i == chosen ? 255 : 180);
	}

	for each (GameString* str in gameStrs2)
	{
		str->Render();
	}
}

void MenuStage::Update(float _delta)
{
	choose->positionX = objects[chosen]->positionX;
	choose->positionY = objects[chosen]->positionY;
	choose->UpdateProcess(_delta);
}

void MenuStage::ProcessKeyboard()
{
	for (DWORD i = 0; i < DiMngr::GetInstance().dwElements; i++)
	{
		DWORD _keyCode = DiMngr::GetInstance().KeyEvents[i].dwOfs;
		DWORD _keyState = DiMngr::GetInstance().KeyEvents[i].dwData;

		switch (_keyCode)
		{
		case DIK_LEFT:
			if ((_keyState & 0x80) > 0)
			{
				chosen--;
				if (chosen < 0)
				{
					chosen += 6;
				}
			}
			break;
		case DIK_RIGHT:
			if ((_keyState & 0x80) > 0)
			{
				chosen++;
				if (chosen >=6 )
				{
					chosen -= 6;
				}
			}
			break;

		case DIK_SPACE:
		case DIK_RETURN:
			if ((_keyState & 0x80) > 0)
			{
				nextStage = GameStage::STAGE_GAMEPLAY;
			}
			break;
		}
	}
}