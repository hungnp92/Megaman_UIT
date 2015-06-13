#include "Mambu.h"

Mambu::Mambu() 
	:GameObj()
{
	LoadSprite(MyResources::GetInstance().sMambu);
	objectType = GameObjectType::o_MAMBU;
	SetStatus(0);
}

Mambu::~Mambu()
{
}

void Mambu::Update(float _delta)
{
	//NextFrame();
}