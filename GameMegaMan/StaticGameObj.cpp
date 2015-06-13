#include "StaticGameObj.h"


StaticGameObj::StaticGameObj()
{
}


StaticGameObj::~StaticGameObj()
{
}

void StaticGameObj::Render(int _alpha)
{
	if (sprite != NULL){
		int top = sprite->spriteStatus[objStatus].top;

		RECT srect;
		srect.left = currentFrame * width;
		srect.top = top;
		srect.right = srect.left + width;
		srect.bottom = srect.top + height;

		//Transformation matrix
		D3DXMATRIX mt;
		D3DXMatrixIdentity(&mt);
		mt._22 = -1.0f;
		mt._41 = 0;
		mt._42 = VIEWPORT_HEIGHT;

		D3DXVECTOR3 position(positionX, positionY, 0);
		D3DXVECTOR4 vp_pos;
		D3DXVec3Transform(&vp_pos, &position, &mt);

		//FlipY
		D3DXVECTOR2 center_scale(vp_pos.x, vp_pos.y);

		D3DXVECTOR2 scale(1, 1);

		D3DXMatrixTransformation2D(&mt, &center_scale, 0, &scale, NULL, NULL, NULL);

		DxMngr::GetInstance().spriteHandler->SetTransform(&mt);

		D3DXVECTOR3 transPosition(vp_pos.x, vp_pos.y, 0.0f);

		//Render
		D3DXVECTOR3 center((float)width / 2, (float)height / 2, 0);

		DxMngr::GetInstance().spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		DxMngr::GetInstance().spriteHandler->Draw(
			sprite->texture,
			&srect,
			&center,
			&transPosition,
			D3DCOLOR_ARGB(_alpha, 255, 255, 255)
			//D3DCOLOR_XRGB(255, 255, 255)
			);
		DxMngr::GetInstance().spriteHandler->End();
	}
}