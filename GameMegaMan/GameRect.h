#pragma once
#include "DxMngr.h"
#include "ViewPort.h"
class GameRect
{
public:
	GameRect(int _top, int _left, int _bottom, int _right, D3DCOLOR _color);
	~GameRect();
	void Render();
protected:
	int r_top, r_left, r_bottom, r_right;
	LPDIRECT3DSURFACE9 _surface = NULL;
};