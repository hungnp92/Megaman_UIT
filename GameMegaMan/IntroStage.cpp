#include "IntroStage.h"

IntroStage::IntroStage()
{
	backColor = D3DCOLOR_XRGB(255, 255, 255);
	rect1 = new GameRect(VIEWPORT_HEIGHT, 0, 0, VIEWPORT_WIDTH, D3DCOLOR_XRGB(64, 96, 248));
	rect2 = new GameRect(VIEWPORT_HEIGHT - 80, 0, 80, VIEWPORT_WIDTH, D3DCOLOR_XRGB(48, 80, 128));
	string1 = new GameString("CUTMAN");
	string2 = new GameString("CLEAR POINT");
	string3 = new GameString("90000", true);
	string1->SetPosision(128, 136);
	string2->SetPosision(111, 136);
	string3->SetPosision(96, 144);
}

IntroStage::~IntroStage()
{}

void IntroStage::Release()
{}

void IntroStage::Render()
{
	rect1->Render();
	rect2->Render();
	string1->Render();
	string2->Render();
	string3->Render();
}

void IntroStage::Update(float _delta)
{}

void IntroStage::ProcessKeyboard()
{}