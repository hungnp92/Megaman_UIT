#include "GameRect.h"

GameRect::GameRect(int _top, int _left, int _bottom, int _right, D3DCOLOR _color)
{
	r_top = _top;
	r_left = _left;
	r_bottom = _bottom;
	r_right = _right;
	DxMngr::GetInstance().FillColor(&_surface, _color);
}

GameRect::~GameRect()
{
}

void GameRect::Render()
{
	RECT rect;
	rect.top = VIEWPORT_HEIGHT - r_top;
	rect.left = r_left;
	rect.bottom = VIEWPORT_HEIGHT - r_bottom;
	rect.right = r_right;
	DxMngr::GetInstance().BlitToSurface(_surface, NULL, &rect);
}