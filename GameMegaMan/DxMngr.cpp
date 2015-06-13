#include "DxMngr.h"

DxMngr::DxMngr()
{
	pD3d = NULL;
	pD3dDevice = NULL;
}

DxMngr::~DxMngr()
{
}

bool DxMngr::Initialize(HWND wndHandle, int _width, int _height)
{
	pD3d = Direct3DCreate9(D3D_SDK_VERSION);	

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = _width;
	d3dpp.BackBufferHeight = _height;
	d3dpp.hDeviceWindow = wndHandle;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.EnableAutoDepthStencil = TRUE;

	if (FAILED(pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, wndHandle, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &pD3dDevice)))
	{
		return false;
	}

	pD3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	pD3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	pD3dDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
	pD3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	D3DXCreateSprite(pD3dDevice, &spriteHandler);
	return true;
}

void DxMngr::Shutdown()
{
	if (pD3dDevice != NULL)
	{
		pD3dDevice->Release();
		pD3dDevice = NULL;
	}

	if (pD3d != NULL)
	{
		pD3d->Release();
		pD3d = NULL;
	}
}

void DxMngr::BeginRender()
{
	if (pD3dDevice == NULL)
	{
		return;
	}
	// Clear the backbuffer to a black color
	pD3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(55, 55, 55), 1.0f, 0);
	pD3dDevice->BeginScene();
}

void DxMngr::EndRender(void)
{
	pD3dDevice->EndScene();
	// Present the backbuffer contents to the display
	pD3dDevice->Present(NULL, NULL, NULL, NULL);
}

IDirect3DSurface9* DxMngr::GetSurfaceFromBitmap(std::string filename)
{
	HRESULT hResult;
	IDirect3DSurface9* surface = NULL;
	D3DXIMAGE_INFO imageInfo;

	// Get the width and height info from this bitmap
	hResult = D3DXGetImageInfoFromFile(filename.c_str(), &imageInfo);
	if FAILED(hResult)
	{
		return NULL;
	}

	hResult = pD3dDevice->CreateOffscreenPlainSurface(imageInfo.Width, imageInfo.Height, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &surface, NULL);
	if (FAILED(hResult))
	{
		return NULL;
	}

	hResult = D3DXLoadSurfaceFromFile(surface, NULL, NULL, filename.c_str(), NULL, D3DX_DEFAULT, 0, NULL);
	if (FAILED(hResult))
	{
		return NULL;
	}

	return surface;
}

LPDIRECT3DTEXTURE9 DxMngr::GetTextureFromBitmap(std::string filename, D3DCOLOR transparentColor)
{
	LPDIRECT3DTEXTURE9 textureImage;
	HRESULT hResult;
	D3DXIMAGE_INFO info;

	hResult = D3DXGetImageInfoFromFile(filename.c_str(), &info);

	if (FAILED(hResult))
	{
		return NULL;
	}

	hResult = D3DXCreateTextureFromFileEx(
		pD3dDevice,
		filename.c_str(),
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		NULL,
		&textureImage);

	if (FAILED(hResult))
	{
		return NULL;
	}
	return textureImage;
}

IDirect3DSurface9* DxMngr::GetBackBuffer(void)
{
	IDirect3DSurface9* backbuffer = NULL;

	if (!pD3dDevice)
	{
		return NULL;
	}

	HRESULT hResult = pD3dDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);
	if (FAILED(hResult))
	{
		return NULL;
	}
	else
	{
		return backbuffer;
	}
}

void DxMngr::BlitToSurface(IDirect3DSurface9* srcSurface, const RECT *srcRect, const RECT *destRect)
{
	pD3dDevice->StretchRect(srcSurface, srcRect, GetBackBuffer(), destRect, D3DTEXF_NONE);
}

void DxMngr::SetBackgroundColor(D3DCOLOR brColor)
{
	pD3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, brColor, 1.0f, 0);
}

void DxMngr::CreateSolidTexture(IDirect3DTexture9 **_ppD3Dtex, DWORD _color)
{
	UINT _with = 5;
	UINT _height = 5;

	pD3dDevice->CreateTexture(_with, _height, 1, 0, D3DFMT_X8R8G8B8, D3DPOOL_MANAGED, _ppD3Dtex, NULL);
	
	WORD colour16 = ((WORD)((_color >> 28) & 0xF) << 12)
		| (WORD)(((_color >> 20) & 0xF) << 8)
		| (WORD)(((_color >> 12) & 0xF) << 4)
		| (WORD)(((_color >> 4) & 0xF) << 0);

	D3DLOCKED_RECT d3dlr;
	(*_ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
	WORD *pDst16 = (WORD*)d3dlr.pBits;

	for (int xy = 0; xy < _with* _height; xy++)
		*pDst16++ = colour16;

	(*_ppD3Dtex)->UnlockRect(0);
}

void DxMngr:: FillColor(IDirect3DSurface9** _surface, D3DCOLOR _color)
{
	pD3dDevice ->CreateOffscreenPlainSurface(
		1,			
		1,			
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		_surface,
		NULL);
	pD3dDevice->ColorFill(*_surface, NULL, _color);
}