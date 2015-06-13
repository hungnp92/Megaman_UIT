#include "PlayStage.h"

PlayStage::PlayStage(string _filename)
{
	nextStage = GameStage::STAGE_NONE;
	Initialize("Resources/Maps/"+ _filename);
	g_Status = GameStatus::RUNING;
}

PlayStage::~PlayStage()
{
}

void PlayStage::Initialize(string _filename)
{
	g_Map = new Map(_filename);
	backColor = g_Map->backColor;
	g_Rockman = new RockMan();
	g_Rockman->positionX = g_Map->startPoint.x+170;
	g_Rockman->positionY = g_Map->startPoint.y;
	g_Rockman->RefreshBoundary();

	ViewPort::GetInstance().SetDirection(g_Map->cameraDirection);
	ViewPort::GetInstance().SetToDefault();
}

void PlayStage::Release()
{ }

void PlayStage::Render()
{
	RECT rect = ViewPort::GetInstance().GetBoundaryRectangle();
	set<GameObj*, RenderComparator> g_RenderObjects;
	switch (g_Status)
	{
	case RUNING:
	case PAUSE:
		g_RenderObjects = g_CurrentNode->GetRenderObjects(rect);
		break;
	case CAMERA_UP:
	case CAMERA_DOWN:
	case CAMERA_LEFT:
	case CAMERA_RIGHT:
		g_RenderObjects = g_CurrentNode->GetBackgroundRenderObjects(rect);
		break;
	}

	g_RenderObjects.insert(g_Rockman);
	for each (GameObj* obj in g_RenderObjects)
	{
		obj->Render();
	}
}

void PlayStage::Update(float _delta)
{
	RECT rect = ViewPort::GetInstance().GetBoundaryRectangle();
	g_CurrentNode = g_Map->GetContainNode(rect);
	switch (g_Status)
	{
	case RUNING:
		g_CollideObjects = g_CurrentNode->GetColideObjects(rect);
		g_DynamicObjects = g_CurrentNode->GetDynamicObjects(rect);

		UpdatePosision(_delta);
		UpdateCollision(_delta);
		AIControl();
		UpdateViewPort();
		UpdateMap();
		RefreshBoundary(); 
		break;
	case CAMERA_UP:
	case CAMERA_DOWN:
	case CAMERA_LEFT:
	case CAMERA_RIGHT:
		UpdateViewPort();
		UpdateMap();
		break;
	}
}

void PlayStage::ProcessKeyboard()
{
	if (DiMngr::GetInstance().keyState[DIK_RIGHT] && g_Status == GameStatus::RUNING)
	{
	
	}

	if (DiMngr::GetInstance().keyState[DIK_LEFT] && g_Status == GameStatus::RUNING)
	{
		
	}

	if (DiMngr::GetInstance().keyState[DIK_UP] && g_Status == GameStatus::RUNING)
	{

	}

	if (DiMngr::GetInstance().keyState[DIK_DOWN] && g_Status == GameStatus::RUNING)
	{

	}

	for (DWORD i = 0; i < DiMngr::GetInstance().dwElements; i++)
	{
		DWORD _keyCode = DiMngr::GetInstance().KeyEvents[i].dwOfs;
		DWORD _keyState = DiMngr::GetInstance().KeyEvents[i].dwData;

		switch (_keyCode)
		{
		case DIK_X:
			if ((_keyState & 0x80) > 0 && g_Status == GameStatus::RUNING)
			{
				//Shoot
			}
			break;
		case DIK_Z:
			if ((_keyState & 0x80) > 0 && g_Status == GameStatus::RUNING)
			{
				//Jump
			}
			break;
		case DIK_RETURN:
			if ((_keyState & 0x80) > 0)
			{
				if (g_Status == GameStatus::RUNING) 
				{
					g_Status = GameStatus::PAUSE;
				}
				else
				{
					if (g_Status == GameStatus::PAUSE)
					{
						g_Status = GameStatus::RUNING;
					}
				}
			}
			break;


		case DIK_SPACE://Test
			if ((_keyState & 0x80) > 0)
			{
				RemoveAllObject();
			}
			break;
		case DIK_A:
			g_Status = GameStatus::CAMERA_RIGHT;
			break;
		case DIK_D:
			g_Status = GameStatus::CAMERA_LEFT;
			break;
		case DIK_S:
			g_Status = GameStatus::CAMERA_DOWN;
			break;
		case DIK_W:
			/* g_Rockman->SetStatus(RockManStatus::RockManIntro);*/
			 g_Status = GameStatus::CAMERA_UP;
			break;
		}
	}

}

void PlayStage::UpdatePosision(float _delta)
{
	for each (GameObj* obj in g_DynamicObjects)
	{
		if (obj->isAlive)
		{
			obj->UpdateProcess(_delta);
		}
	}
	g_Rockman->UpdateProcess(_delta);
}

void PlayStage::UpdateCollision(float _delta)
{
	g_CollideObjects.insert(g_Rockman);
	for each (GameObj* obj1 in g_CollideObjects)
	{
		for each (GameObj* obj2 in g_CollideObjects)
		{
			if (obj1 != obj2)
			{
				float normalx, normaly;
				float collisiontime = CollisionMngr::GetInstance().SweptAABB(obj1, obj2, normalx, normaly);
				obj1->CollisionProcess(obj2, _delta, collisiontime, normalx, normaly);
			}
		}
	}
}

void PlayStage::UpdateViewPort()
{
	int temp = g_ViewPortSpeed * GAME_FRAME_RATE / 1000;
 	switch (g_Status)
	{
	case CAMERA_UP:
		ViewPort::GetInstance().MoveY(2);
		break;
	case CAMERA_DOWN:
		ViewPort::GetInstance().MoveY(-2);
		break;
	case CAMERA_LEFT:
		ViewPort::GetInstance().MoveX(2);
		break;
	case CAMERA_RIGHT:
		ViewPort::GetInstance().MoveX(-2);
		break;
	default:
		ViewPort::GetInstance().MoveX(g_Rockman->positionX - ViewPort::GetInstance().GetCenterX());
		break;
	}
}

void PlayStage::AIControl()
{
	for each (GameObj* obj in g_DynamicObjects)
	{
		if (obj->isAlive)
		{
			obj->AIControl(g_Rockman->positionX, g_Rockman->positionY);
		}
	}
}

void PlayStage::UpdateMap()
{
	RECT rect = ViewPort::GetInstance().GetBoundaryRectangle();
	set<GameObjectType> ignore = { GameObjectType::o_BULLET };
	//Process
	for each (GameObj* obj in g_DynamicObjects)
	{
		RECT objRect = obj->GetCurrentRect();
		g_Map->RemoveGameObject(obj);

		if (ignore.count(obj->objectType) == 0)
		{
			if (!obj->isAlive || !CollisionMngr::RectToRect(rect, objRect))
			{
				obj->SetDefault();
				obj->isAlive = !CollisionMngr::RectToRect(obj->GetCurrentRect(), objRect);
			}

			g_Map->AddGameObject(obj);
		}
		else
		{
			if (obj->isAlive && CollisionMngr::RectToRect(rect, objRect))
			{
				g_Map->AddGameObject(obj);
			}
			else
			{
				if (obj->objectType == o_BULLET)
				{
					GameObj* owner = dynamic_cast<BulletObj*>(obj)->b_owner;

					if (owner != NULL&& owner->o_bulletCount > 0)
					{
						owner->o_bulletCount--;
					}
				}
			}
		}

		for(int i = 0; i< obj->buffer.size(); i++)
		{
			g_Map->AddGameObject(obj->buffer[i]);
		}
		obj->buffer.clear();
	}
}

void PlayStage::RefreshBoundary()
{
	for each (GameObj* obj in g_DynamicObjects)
	{
		if (obj != NULL)
		{
			obj->RefreshBoundary();
		}
	}
	g_Rockman->RefreshBoundary();
}

void PlayStage::RemoveAllObject()
{
	for each (GameObj* obj in g_DynamicObjects)
	{
		if (obj->objectType != GameObjectType::o_BRICK)
		{
			obj->isAlive = false;
		}
	}
}