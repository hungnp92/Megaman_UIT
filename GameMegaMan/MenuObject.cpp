#include "MenuObject.h"

MenuObject::MenuObject(Sprite* _sprite)
{
	LoadSprite(_sprite);
	SetStatus(0);
	SetFrameRate(8);
}

MenuObject::~MenuObject()
{ }

void MenuObject::Update(float _delta)
{
	NextFrame();
}