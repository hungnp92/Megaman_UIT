#include "SpriteStatus.h"

SpriteStatus::SpriteStatus()
{
	statusID = -1;
	frameCount = 0;
	frameWidth = 0;
	frameHeight = 0;
	top = 0;
}

SpriteStatus::~SpriteStatus()
{
}

SpriteStatus::SpriteStatus(int _id, int _count, int _width, int _height, int _top)
{
	statusID = _id;
	frameCount = _count;
	frameWidth = _width;
	frameHeight = _height;
	top = _top;
}

SpriteStatus::SpriteStatus(int _count, int _width, int _height, int _top)
{
	statusID = 0;
	frameCount = _count;
	frameWidth = _width;
	frameHeight = _height;
	top = _top;
}