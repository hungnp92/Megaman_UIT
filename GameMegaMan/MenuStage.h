#pragma once
#include "Stage.h"
class MenuStage : public Stage
{
public:
	MenuObject* choose;
	vector<MenuObject*> objects;
	int chosen;
	vector<GameString*> gameStrs;
	vector<GameString*> gameStrs2;

	MenuStage();
	~MenuStage();
	void Release() override;
	void Render() override;
	void Update(float _delta) override;
	void ProcessKeyboard() override;
};