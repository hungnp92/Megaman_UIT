#pragma once
#include <dxdiag.h>
#include <d3dx9.h>
#include <vector>

using namespace std;

#define VIEWPORT_WIDTH 256
#define VIEWPORT_HEIGHT 224

class ViewPort
{
public:
	int positionX, positionY;
	ViewPort();
	~ViewPort();

	RECT GetBoundaryRectangle();
	void SetPosition(int _positionX, int _positionY);
	void SetToDefault();
	void AddToDirection(D3DVECTOR point);
	void SetDirection(vector<D3DVECTOR> points);
	void ClearDirection();
	void MoveX(int _deltaX);
	void MoveY(int _deltaY);
	int GetCenterX();

	static ViewPort& GetInstance()
	{
		static ViewPort viewPort;
		return viewPort;
	}
private:
	vector<D3DVECTOR> v_directions;
	bool IsInPath(int posX, int posY, D3DVECTOR point1, D3DVECTOR point2);
	int const v_gradTop = 32;
	int const v_gradBottom = -32;
	int const v_gradRight = 32;
	int const v_gradLeft = -32;
};