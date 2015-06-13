#include "Map.h"

Map::Map(string _filename) 
	:QuadNode()
{
	backColor = D3DCOLOR_XRGB(0, 0, 0);
	startPoint.x = 0;
	startPoint.y = 0;
	LoadMap(_filename);
}


Map::~Map()
{
}

void Map::LoadMap(string filename)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(filename.c_str());
	XMLElement* root = doc.FirstChildElement("Map");
	XMLElement* objectElement = root->FirstChildElement("GameObjects");
	XMLElement* nodeElement = root->FirstChildElement("Nodes");
	XMLElement* cameraElement = root->FirstChildElement("Camera");

	backColor = D3DCOLOR_XRGB(atoi(root->Attribute("R")), atoi(root->Attribute("G")), atoi(root->Attribute("B")));
	startPoint.x = atoi(root->Attribute("X"));
	startPoint.y = atoi(root->Attribute("Y"));

	vector<GameObj*> objects = GetAllGameObjects(objectElement);
	GetQuadNode(nodeElement, objects);
	cameraDirection = GetViewPortDirection(cameraElement);
}

GameObj* Map::CreateGameObject(XMLElement* element)
{
	GameObjectType type = (GameObjectType)atoi(element->Attribute("Type"));
	int posisionX = (GameObjectType)atoi(element->Attribute("PosisionX"));
	int posisionY = (GameObjectType)atoi(element->Attribute("PosisionY"));
	int width = (GameObjectType)atoi(element->Attribute("Width"));
	int height = (GameObjectType)atoi(element->Attribute("Height"));
	int state = (GameObjectType)atoi(element->Attribute("State"));

	return GameObjMngr::CreateGameObject(type, posisionX, posisionY, width, height, state);
}

QuadNode* Map::CreateQuadNode(XMLElement* element, vector<GameObj*> objects)
{
	string id = element->Attribute("Id");
	int posX = atoi(element->Attribute("X"));
	int posY = atoi(element->Attribute("Y"));
	int width = atoi(element->Attribute("Width"));
	int height = atoi(element->Attribute("Height"));
	QuadNode* result = new QuadNode(id, posX, posY, width, height);
	XMLElement* e = element->FirstChildElement("ObjectId");
	while (e != NULL)
	{
		int index = atoi(e->Attribute("Id"));
		result->objects.insert(objects[index]);
		e = e->NextSiblingElement("ObjectId");
	}
	return result;
}

vector<GameObj*> Map::GetAllGameObjects(XMLElement* element)
{
	vector<GameObj*> result;
	XMLElement* e = element->FirstChildElement("Object");
	while (e != NULL)
	{
		result.push_back(CreateGameObject(e));
		e = e->NextSiblingElement("Object");
	}

	return result;
}

vector<D3DVECTOR> Map::GetViewPortDirection(XMLElement* element)
{
	vector<D3DVECTOR> result;
	XMLElement* e = element->FirstChildElement("Point");
	while (e != NULL)
	{
		D3DVECTOR point;
		point.x = atoi(e->Attribute("X"));
		point.y = atoi(e->Attribute("Y"));
		point.z = 0;
		result.push_back(point);
		e = e->NextSiblingElement("Point");
	}
	return result;
}

void Map::GetQuadNode(XMLElement* element, vector<GameObj*> objects)
{
	XMLElement* e = element->FirstChildElement("Node");
	while (e!=NULL)
	{
		QuadNode* node = CreateQuadNode(e, objects);
		AddNode(node, node->id);
		e = e->NextSiblingElement("Node");
	}
}
