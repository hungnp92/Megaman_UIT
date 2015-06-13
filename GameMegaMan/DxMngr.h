#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <string>

#define GAME_FRAME_RATE 60
#define WINDOWS_SCALE 2
#define WINDOWS_FULLSCREEN false

class DxMngr
{
public:
	DxMngr();
	~DxMngr();

	bool Initialize(HWND _wndHandle, int _width, int _height);
	void Shutdown();
	void BeginRender();
	void EndRender();
	void SetBackgroundColor(D3DCOLOR brColor);

	void CreateSolidTexture(IDirect3DTexture9 **_ppD3Dtex, DWORD _color);
	void FillColor(IDirect3DSurface9** _surface, D3DCOLOR _color);


	IDirect3DSurface9* GetSurfaceFromBitmap(std::string filename);
	LPDIRECT3DTEXTURE9 GetTextureFromBitmap(std::string filename, D3DCOLOR transparentColor);
	void BlitToSurface(IDirect3DSurface9* srcSurface, const RECT *srcRect, const RECT *destRect);	
	IDirect3DSurface9* GetBackBuffer();
	LPD3DXSPRITE spriteHandler;

	static DxMngr& GetInstance()
	{
		static DxMngr dxMngr;
		return dxMngr;
	}
	
private:
	LPDIRECT3D9             pD3d;
	LPDIRECT3DDEVICE9       pD3dDevice;
};

