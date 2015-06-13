#include "GameString.h"

GameString::GameString(string _message, bool _bold)
{
	s_value = _message;
	s_bold = _bold;
	s_top = 0;
	s_left = 0;
	s_length = _message.length();

	SnipCharactor();
}

GameString::~GameString()
{
}

void GameString::SetPosision(int _top, int _left)
{
	s_top = _top;
	s_left = _left;
	for (int i = 0; i < s_length; i++)
	{
		characters[i]->positionX = _left + i * characters[i]->width + characters[i]->width / 2;
		characters[i]->positionY = _top - characters[i]->height / 2;
	}
}

void GameString::SetTop(int _top)
{
	s_top = _top;
	for (int i = 0; i < s_length; i++)
	{
		characters[i]->positionY = _top - characters[i]->height / 2;
	}
}

void GameString::Render(int _alpha)
{
	for each (CharacterTitle* _char in characters)
	{
		_char->Render(_alpha);
	}
}

void GameString::SnipCharactor()
{
	for (int i = 0; i < s_value.length(); i++)
	{
		CharacterTitle* _char = new CharacterTitle(s_value[i], s_bold);
		_char->positionX = s_left + i * _char->width + _char->width / 2;
		_char->positionY = s_top - _char->height / 2;
		characters.push_back(_char);
	}
}

void GameString::SetCenter(int screen_left, int screen_width)
{
	int width = 0;
	for each (CharacterTitle* _char in characters)
	{
		width += _char->width;
	}

	SetPosision(s_top, screen_left + (screen_width - width) / 2);
}

void GameString::SetValue(string _value)
{
	if (_value != s_value)
	{
		characters.clear();
		s_value = _value;
		s_length = _value.length();
		SnipCharactor();
	}
}