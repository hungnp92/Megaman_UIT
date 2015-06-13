#pragma once
#include <string>
using namespace std;
class SpriteStatus
{
public:
	int statusID;
	float frameWidth;
	float frameHeight;
	int frameCount;
	int top;
	SpriteStatus();
	~SpriteStatus();
	SpriteStatus(int _id, int _count, int _width, int _height, int _top);
	SpriteStatus(int _count, int _width, int _height, int _top);
};

