#pragma once
#include "StaticGameObj.h"
class CharacterTitle :public StaticGameObj
{
public:
	CharacterTitle(char _char, bool _bold = false);
	~CharacterTitle();
private:
	int GetFrameNumber(char _char, bool _bold);
	const string characters_nomal = " ABCDEFGHIJKLMNOPQRSTUVWXYZr.,'!©1978?-";
	const string characters_bold = " 0123456789ABCEFGILMNOPRTU=-x";
};