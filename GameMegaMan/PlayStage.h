#pragma once
#include "Map.h"
#include "Stage.h"
#include "CollisionMngr.h"

enum GameStatus
{
	RUNING,
	PAUSE,
	CAMERA_UP,
	CAMERA_DOWN,
	CAMERA_LEFT,
	CAMERA_RIGHT
};

class PlayStage : public Stage
{
public:
	PlayStage(string _filename);
	~PlayStage();

	void Initialize(string _filename);
	void Release() override;
	void Render() override;
	void Update(float _delta) override;
	void ProcessKeyboard() override;
protected:
	GameStatus g_Status;
	Map* g_Map;
	RockMan* g_Rockman;
	GameString* g_PauseStr;
	int g_ViewPortMove;
	const int g_VerticalDistance = 240;
	const int g_HorizontalDistance = 256;
	const int g_ViewPortSpeed = 40;

	QuadNode* g_CurrentNode;
	set<GameObj*, CollisionComparator> g_CollideObjects;
	set<GameObj*> g_DynamicObjects;

	void UpdatePosision(float _delta);
	void UpdateCollision(float _delta);
	void UpdateViewPort();
	void AIControl();
	void UpdateMap();
	void RefreshBoundary();
	void RemoveAllObject();
};

