#pragma once
#include "QuadNode.h"
#include "tinyxml2.h"
#include "GameObjMngr.h"

using namespace tinyxml2;

class Map :
	public QuadNode
{
public:
	D3DCOLOR backColor;
	vector<D3DVECTOR> cameraDirection;
	D3DVECTOR startPoint;

	Map(string filename);
	~Map();
private:
	void LoadMap(string filename);
	GameObj* CreateGameObject(XMLElement* element);
	QuadNode* CreateQuadNode(XMLElement* element, vector<GameObj*> objects);
	vector<GameObj*> GetAllGameObjects(XMLElement* element);
	void GetQuadNode(XMLElement* element, vector<GameObj*> objects);
	vector<D3DVECTOR> GetViewPortDirection(XMLElement* element);	
};