#pragma once
#include <vector>
#include "CharacterTitle.h"
using namespace std;
class GameString
{
public:
	string s_value; 
	bool s_bold;
	int s_top, s_left, s_length;

	GameString(string _message, bool _bold = false);
	~GameString();

	void Render(int _alpha = 255);
	void SetPosision(int _top, int _left);
	void SetTop(int _top);
	void SetCenter(int screen_left = 0, int screen_width = VIEWPORT_WIDTH);
	void SetValue(string _value);
private:
	vector<CharacterTitle*> characters;	
	void SnipCharactor();
};

