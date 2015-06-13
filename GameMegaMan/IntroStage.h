#pragma once
#include "Stage.h"
#include "GameRect.h"

class IntroStage
	: public Stage
{
public:
	IntroStage();
	~IntroStage();
	void Release() override;
	void Render() override;
	void Update(float _delta) override;
	void ProcessKeyboard() override;
private:
	GameRect* rect1;
	GameRect* rect2;
	GameString* string1;
	GameString* string2;
	GameString* string3;
};