#pragma once
#include "Stage.h"
class WelcomeStage :
	public Stage
{
public:
	WelcomeStage();
	~WelcomeStage();
	void Release() override;
	void Render() override;
	void Update(float _delta) override;
	void ProcessKeyboard() override;
private:
	MenuObject* banner;
	GameString* stringTM;
	GameString* strStart;
	GameString* string1;
	GameString* string2;
	GameString* string3;

	float deltaTime = 0;
	float frameTime = 1.0f / 10;
	bool isRender = true;
};

