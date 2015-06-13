#include "ViewPort.h"

ViewPort::ViewPort()
{
	SetPosition(0, 0);
}

ViewPort::~ViewPort()
{
}

void ViewPort::SetPosition(int _positionX, int _positionY)
{
	positionX = _positionX;
	positionY = _positionY;
}

void ViewPort::SetToDefault()
{
	if (v_directions.size() > 0)
	{
		SetPosition(v_directions[0].x, v_directions[0].y);
	}
	else
	{
		SetPosition(0, VIEWPORT_HEIGHT);
	}
}

RECT ViewPort::GetBoundaryRectangle()
{
	RECT rec;
	rec.left = max(0, positionX + v_gradLeft);
	rec.right = max(0, positionX + VIEWPORT_WIDTH + v_gradRight);
	rec.top = max(0, positionY + v_gradTop);
	rec.bottom = max(0, positionY - VIEWPORT_HEIGHT + v_gradBottom);
	return rec;
}

void ViewPort::AddToDirection(D3DVECTOR point)
{
	v_directions.push_back(point);
}

void ViewPort::SetDirection(vector<D3DVECTOR> points)
{
	v_directions = points;
}

void ViewPort::ClearDirection()
{
	v_directions.clear();
}

void ViewPort::MoveX(int _deltaX)
{
	int newPosX = positionX + _deltaX;
	if (v_directions.size() >= 2)
	{
		for (int i = 0; i < v_directions.size() - 1; i++)
		{
			D3DVECTOR point1 = v_directions[i];
			D3DVECTOR point2 = v_directions[i+1];
			if (IsInPath(newPosX, positionY, point1, point2))
			{
				positionX = newPosX;
				return;
			}
		}

		for (int i = 0; i < v_directions.size() - 1; i++)
		{
			D3DVECTOR point1 = v_directions[i];
			D3DVECTOR point2 = v_directions[i + 1];
			if (IsInPath(positionX, positionY, point1, point2))
			{
				if (newPosX > max(point1.x, point2.x))
				{
					newPosX = max(point1.x, point2.x);
				}

				if (newPosX < min(point1.x, point2.x))
				{
					newPosX = min(point1.x, point2.x);
				}
				positionX = newPosX;
				return;
			}
		}
	}

	positionX = newPosX;
}

void ViewPort::MoveY(int _deltaY)
{
	int newPosY = positionY + _deltaY;
	if (v_directions.size() >= 2)
	{
		for (int i = 0; i < v_directions.size() - 1; i++)
		{
			D3DVECTOR point1 = v_directions[i];
			D3DVECTOR point2 = v_directions[i + 1];
			if (IsInPath(positionX, newPosY, point1, point2))
			{
				positionY = newPosY;
				return;
			}
		}

		for (int i = 0; i < v_directions.size() - 1; i++)
		{
			D3DVECTOR point1 = v_directions[i];
			D3DVECTOR point2 = v_directions[i + 1];
			if (IsInPath(positionX, positionY, point1, point2))
			{
				if (newPosY > max(point1.y, point2.y))
				{
					newPosY = max(point1.y, point2.y);
				}

				if (newPosY < min(point1.y, point2.y))
				{
					newPosY = min(point1.y, point2.y);
				}
				positionY = newPosY;
				return;
			}
		}
	}

	positionX = newPosY;
}

bool ViewPort::IsInPath(int posX, int posY, D3DVECTOR point1, D3DVECTOR point2)
{
	return (point1.x == posX && point2.x == posX && posY >= min(point1.y, point2.y) && posY <= max(point1.y, point2.y))
		|| (point1.y == posY && point2.y == posY && posX >= min(point1.x, point2.x) && posX <= max(point1.x, point2.x));
}

int ViewPort::GetCenterX()
{
	return positionX + VIEWPORT_WIDTH / 2;
}