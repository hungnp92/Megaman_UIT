#include "CharacterTitle.h"

CharacterTitle::CharacterTitle(char _char, bool _bold)
	:StaticGameObj()
{	
	objectType = GameObjectType::o_BACKGROUND;
	if (_bold){
		LoadSprite(MyResources::GetInstance().sCharactersBold);
	}
	else
	{
		LoadSprite(MyResources::GetInstance().sCharactersNormal);
	}
	
	SetStatus(0);
	currentFrame = GetFrameNumber(_char, _bold);
}

CharacterTitle::~CharacterTitle()
{
}

int CharacterTitle::GetFrameNumber(char _char, bool _bold)
{
	if (_bold)
	{
		return max(0, characters_bold.find(_char));
	}
	else
	{
		return max(0, characters_nomal.find(_char));
	}
}
