#pragma once
#include <Windows.h>
#include "DxMngr.h"
#include "DiMngr.h"
#include "ViewPort.h"

#include "PlayStage.h"
#include "MenuStage.h"
#include "IntroStage.h"
#include "WelcomeStage.h"
using namespace std;

class Game
{
private:
	DWORD deltaTime;
	DWORD lastTime;
	bool isFullScreen;
	int frameRate;
	int screenWidth;
	int screenHeight;
	int viewportWidth;
	int viewportHeight;
	Stage *stage;

	HINSTANCE hInstance;
	HWND wndHandle;
	LPSTR wndName;

	bool InitWindow();
	bool InitDirectX();
	bool InitDirectInput();
	void UpdateWorld(float delta);
	void RenderFrame();
	void LoadResource();
	void ProcessKeyboard();
	void ChangeStage();
	void Release();

	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM);

public:
	Game(HINSTANCE _hInstance, LPSTR _name, int _screenWidth, int _screenHeight, bool _isFullScreen, int _frameRate);
	~Game();
	bool Initialize();
	void Run();
};

