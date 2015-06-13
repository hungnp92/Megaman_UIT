#pragma once
#include "DiMngr.h"
#include "GameString.h"
#include "MenuObject.h"
#include "GameRect.h"
using namespace std;

class Stage
{
public:
	GameStage nextStage;
	D3DCOLOR backColor;

	virtual void Release();
	virtual void Render();
	virtual void Update(float _delta);

	virtual void ProcessKeyboard();

	Stage();
	~Stage();
};