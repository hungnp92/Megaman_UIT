#include "QuadNode.h"


QuadNode::QuadNode()
{
	id = "";
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	childrentNodes[0] = NULL;
	childrentNodes[1] = NULL;
	childrentNodes[2] = NULL;
	childrentNodes[3] = NULL;
}

QuadNode::QuadNode(string _id, int _x, int _y, int _width, int _height)
{
	id = _id;
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	childrentNodes[0] = NULL;
	childrentNodes[1] = NULL;
	childrentNodes[2] = NULL;
	childrentNodes[3] = NULL;
}

QuadNode::~QuadNode()
{
}

void QuadNode::AddNode(QuadNode* _node, string _nodeId)
{
	_nodeId = _nodeId.substr(1);
	if (_nodeId.empty())
	{
		id = _node->id;
		x = _node->x;
		y = _node->y;
		width = _node->width;
		height = _node->height;
		objects = _node->objects;
	}
	else
	{
		int id = stoi(_nodeId.substr(0, 1));
		if (childrentNodes[id] == NULL)
		{
			childrentNodes[id] = new QuadNode();
		}
		childrentNodes[id]->AddNode(_node, _nodeId);
	}
}

set<GameObj*> QuadNode::GetAllObjects()
{
	set<GameObj*> result;
	for each (GameObj* obj in objects)
	{
		if (obj != NULL)
		{
			result.insert(obj);
		}
	}

	if (childrentNodes[0] != NULL)
	{
		set<GameObj*> result0 = childrentNodes[0]->GetAllObjects();
		set<GameObj*> result1 = childrentNodes[1]->GetAllObjects();
		set<GameObj*> result2 = childrentNodes[2]->GetAllObjects();
		set<GameObj*> result3 = childrentNodes[3]->GetAllObjects();
		result.insert(result0.begin(), result0.end());
		result.insert(result1.begin(), result1.end());
		result.insert(result2.begin(), result2.end());
		result.insert(result3.begin(), result3.end());
	}
	return result;
}

set<GameObj*, RenderComparator> QuadNode::GetBackgroundRenderObjects(RECT rect)
{
	set<GameObjectType> Types = { GameObjectType::o_BACKGROUND, GameObjectType::o_BRICK };
	set<GameObj*, RenderComparator> result;
	for each (GameObj* obj in objects)
	{
		if (obj != NULL && obj->isAlive && Types.count(obj->objectType) != 0 && RectToRect(rect, obj->GetCurrentRect()))
		{
			result.insert(obj);
		}
	}

	if (childrentNodes[0] != NULL)
	{
		if (childrentNodes[0]->IsCollideWithRECT(rect))
		{
			set<GameObj*, RenderComparator> result0 = childrentNodes[0]->GetRenderObjects(rect);
			result.insert(result0.begin(), result0.end());
		}

		if (childrentNodes[1]->IsCollideWithRECT(rect))
		{
			set<GameObj*, RenderComparator> result1 = childrentNodes[1]->GetRenderObjects(rect);
			result.insert(result1.begin(), result1.end());
		}

		if (childrentNodes[2]->IsCollideWithRECT(rect))
		{
			set<GameObj*, RenderComparator> result2 = childrentNodes[2]->GetRenderObjects(rect);
			result.insert(result2.begin(), result2.end());
		}

		if (childrentNodes[3]->IsCollideWithRECT(rect))
		{
			set<GameObj*, RenderComparator> result3 = childrentNodes[3]->GetRenderObjects(rect);
			result.insert(result3.begin(), result3.end());
		}
	}
	return result;
}

set<GameObj*, RenderComparator> QuadNode::GetRenderObjects(RECT rect)
{
	set<GameObjectType> ignoreTypes = { GameObjectType::o_TRANSPARENT, GameObjectType::o_LADDER, GameObjectType::o_FLAG, GameObjectType::o_FENCE };
	set<GameObj*, RenderComparator> result;
	for each (GameObj* obj in objects)
	{
		if (obj!=NULL && obj->isAlive && ignoreTypes.count(obj->objectType) == 0 && RectToRect(rect, obj->GetCurrentRect()))
		{
			result.insert(obj);
		}
	}

	if (childrentNodes[0] != NULL)
	{
		if (childrentNodes[0]->IsCollideWithRECT(rect))
		{
			set<GameObj*, RenderComparator> result0 = childrentNodes[0]->GetRenderObjects(rect);
			result.insert(result0.begin(), result0.end());
		}

		if (childrentNodes[1]->IsCollideWithRECT(rect))
		{
			set<GameObj*, RenderComparator> result1 = childrentNodes[1]->GetRenderObjects(rect);
			result.insert(result1.begin(), result1.end());
		}

		if (childrentNodes[2]->IsCollideWithRECT(rect))
		{
			set<GameObj*, RenderComparator> result2 = childrentNodes[2]->GetRenderObjects(rect);
			result.insert(result2.begin(), result2.end());
		}

		if (childrentNodes[3]->IsCollideWithRECT(rect))
		{
			set<GameObj*, RenderComparator> result3 = childrentNodes[3]->GetRenderObjects(rect);
			result.insert(result3.begin(), result3.end());
		}
	}
	return result;
}

set<GameObj*, CollisionComparator> QuadNode::GetColideObjects(RECT rect)
{
	set<GameObjectType> ignoreTypes = { GameObjectType::o_BACKGROUND };
	set<GameObj*, CollisionComparator> result;
	for each (GameObj* obj in objects)
	{
		if (obj != NULL && obj->isAlive && ignoreTypes.count(obj->objectType) == 0 && RectToRect(rect, obj->GetCurrentRect()))
		{
   			result.insert(obj);
		}
	}

	if (childrentNodes[0] != NULL)
	{
		if (childrentNodes[0]->IsCollideWithRECT(rect))
		{
			set<GameObj*, CollisionComparator> result0 = childrentNodes[0]->GetColideObjects(rect);
			result.insert(result0.begin(), result0.end());
		}

		if (childrentNodes[1]->IsCollideWithRECT(rect))
		{
			set<GameObj*, CollisionComparator> result1 = childrentNodes[1]->GetColideObjects(rect);
			result.insert(result1.begin(), result1.end());
		}

		if (childrentNodes[2]->IsCollideWithRECT(rect))
		{
			set<GameObj*, CollisionComparator> result2 = childrentNodes[2]->GetColideObjects(rect);
			result.insert(result2.begin(), result2.end());
		}

		if (childrentNodes[3]->IsCollideWithRECT(rect))
		{
			set<GameObj*,CollisionComparator> result3 = childrentNodes[3]->GetColideObjects(rect);
			result.insert(result3.begin(), result3.end());
		}
	}
	return result;
}

set<GameObj*> QuadNode::GetDynamicObjects(RECT rect)
{
	set<GameObjectType> ignoreTypes = { GameObjectType::o_BACKGROUND, GameObjectType::o_TRANSPARENT, GameObjectType::o_LADDER, GameObjectType::o_FLAG, GameObjectType::o_FENCE };
	set<GameObj*> result;
	for each (GameObj* obj in objects)
	{
		if (obj != NULL && ignoreTypes.count(obj->objectType) == 0 && RectToRect(rect, obj->GetCurrentRect()))
		{
			result.insert(obj);
		}
	}

	if (childrentNodes[0] != NULL)
	{
		if (childrentNodes[0]->IsCollideWithRECT(rect))
		{
			set<GameObj*> result0 = childrentNodes[0]->GetDynamicObjects(rect);
			result.insert(result0.begin(), result0.end());
		}

		if (childrentNodes[1]->IsCollideWithRECT(rect))
		{
			set<GameObj*> result1 = childrentNodes[1]->GetDynamicObjects(rect);
			result.insert(result1.begin(), result1.end());
		}

		if (childrentNodes[2]->IsCollideWithRECT(rect))
		{
			set<GameObj*> result2 = childrentNodes[2]->GetDynamicObjects(rect);
			result.insert(result2.begin(), result2.end());
		}

		if (childrentNodes[3]->IsCollideWithRECT(rect))
		{
			set<GameObj*> result3 = childrentNodes[3]->GetDynamicObjects(rect);
			result.insert(result3.begin(), result3.end());
		}
	}
	return result;
}

bool QuadNode::IsContainRECT(RECT rec)
{
	RECT temp;
	temp.left = x;
	temp.right = x + width;
	temp.top = y;
	temp.bottom = y - height;
	return (rec.top <= temp.top) && (rec.bottom >= temp.bottom) && (rec.left >= temp.left) && (rec.right <= temp.right);
}

bool QuadNode::IsCollideWithRECT(RECT rect)
{
	RECT temp;
	temp.left = x;
	temp.right = x + width;
	temp.top = y;
	temp.bottom = y - height;
	return RectToRect(rect, temp);
}

bool QuadNode::RectToRect(RECT rect1, RECT rect2)
{
	return !(rect1.right < rect2.left || rect1.left > rect2.right || rect1.bottom > rect2.top || rect1.top < rect2.bottom);
}

QuadNode* QuadNode::GetContainNode(RECT rect)
{
	if (childrentNodes[0] == NULL)
	{
		return this;
	}

	for (int i = 0; i < 4; i++)
	{
		if (childrentNodes[i]->IsContainRECT(rect))
		{
			return childrentNodes[i]->GetContainNode(rect);
		}
	}
	return this;
}

void QuadNode::AddGameObject(GameObj* obj)
{
	if (obj != NULL)
	{
		QuadNode* node = GetContainNode(obj->GetCurrentRect());
		if (childrentNodes[0] != NULL)
		{
			for (int i = 0; i < 4; i++)
			{
				if (childrentNodes[i]->IsCollideWithRECT(obj->GetCurrentRect()))
				{
					childrentNodes[i]->AddGameObject(obj);
				}
			}
		}
		else
		{
			node->objects.insert(obj);
		}
	}
}

void QuadNode::RemoveGameObject(GameObj* obj)
{
	if (obj != NULL)
	{
		QuadNode* node = GetContainNode(obj->oldRect);
		if (childrentNodes[0] != NULL)
		{
			for (int i = 0; i < 4; i++)
			{
				if (childrentNodes[i]->IsCollideWithRECT(obj->oldRect))
				{
					childrentNodes[i]->RemoveGameObject(obj);
				}
			}
		}
		else
		{
			node->objects.erase(obj);
		}
	}
}