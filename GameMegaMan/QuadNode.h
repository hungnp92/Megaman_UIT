#pragma once
#include <set>
#include "GameObj.h"
struct RenderComparator
{
	bool operator() (GameObj* obj1, GameObj* obj2) const
	{
		int temp = obj1->renderOrder - obj2->renderOrder;
		if (temp != 0)
		{
			return temp < 0;
		}
		else
		{
			return obj1 < obj2;
		}
	}
};

struct CollisionComparator
{
	bool operator() (GameObj* obj1, GameObj* obj2) const
	{
		int temp = obj1->collisionOrder - obj2->collisionOrder;
		if (temp != 0)
		{
			return temp < 0;
		}
		else
		{
			return obj1 < obj2;
		}
	}
};

class QuadNode
{
public:
	string id;
	set<GameObj*> objects;

	QuadNode();
	QuadNode(string _id, int _x, int _y, int _width, int _height);
	~QuadNode();

	set<GameObj*> GetAllObjects();
	set<GameObj*, RenderComparator> GetRenderObjects(RECT rect);
	set<GameObj*, RenderComparator> GetBackgroundRenderObjects(RECT rect);
	set<GameObj*, CollisionComparator> GetColideObjects(RECT rect);
	set<GameObj*> GetDynamicObjects(RECT rect);

	QuadNode* GetContainNode(RECT rect);
	void AddGameObject(GameObj* obj);
	void RemoveGameObject(GameObj* obj);
	void AddNode(QuadNode* _node, string _nodeId);
protected:
	QuadNode* childrentNodes[4];
	int x, y, width, height;
private:
	bool IsContainRECT(RECT rect);
	bool IsCollideWithRECT(RECT rect);
	bool RectToRect(RECT rect1, RECT rect2);
};

