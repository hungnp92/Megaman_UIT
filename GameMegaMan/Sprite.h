#pragma once
#include <map>
#include "SpriteStatus.h"
#include "DxMngr.h"
using namespace std;
class Sprite
{
public:
	LPDIRECT3DTEXTURE9 texture;
	map<int, SpriteStatus> spriteStatus;

	Sprite();
	~Sprite();
	void AddStatus(SpriteStatus _status);
	void LoadSprite(LPDIRECT3DTEXTURE9 _texture);
};
