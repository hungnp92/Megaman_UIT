#include "Sprite.h"

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}

void Sprite::AddStatus(SpriteStatus _status)
{
	spriteStatus.insert(pair<int, SpriteStatus>(_status.statusID, _status));
}

void Sprite::LoadSprite(LPDIRECT3DTEXTURE9 _texture){
	texture = _texture;
}