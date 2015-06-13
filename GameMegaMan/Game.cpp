#include "Game.h"

Game::Game(HINSTANCE _hInstance, LPSTR _name, int _screenWidth, int _screenHeight, bool _isFullScreen, int _frameRate)
{
	wndName = _name;
	isFullScreen = _isFullScreen;
	frameRate = _frameRate;
	screenWidth = _screenWidth;
	screenHeight = _screenHeight;
}

Game::~Game()
{
	/*if (stage != NULL)
	{
		delete stage;
	}*/
}

bool Game::InitWindow()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)Game::WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = wndName;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	DWORD style;
	if (isFullScreen)
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	else
		style =  WS_OVERLAPPEDWINDOW;

	wndHandle =
		CreateWindow(
		wndName,
		wndName,
		style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		screenWidth,
		screenHeight,
		NULL,
		NULL,
		hInstance,
		NULL);

	//SetWindowLong(wndHandle, GWL_STYLE, 1);

	if (!wndHandle)
	{
		return false;
	}

	ShowWindow(wndHandle, SW_SHOWDEFAULT);
	UpdateWindow(wndHandle);

	return true;
}

bool Game::InitDirectX()
{ 
	return DxMngr::GetInstance().Initialize(wndHandle, VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
}

bool Game::InitDirectInput()
{
	return DiMngr::GetInstance().Initialize(wndHandle);
}

LRESULT CALLBACK Game::WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

bool Game::Initialize()
{
	if (!InitWindow()) return false;
	if (!InitDirectX()) return false;
	if (!InitDirectInput()) return false;
	return true;
}

void Game::Run()
{
	LoadResource();
	stage = new WelcomeStage();

	MSG msg;
	int done = 0;
	DWORD frame_start = GetTickCount();

	float tick_per_frame = 1000.0f / frameRate;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				Release();
				done = 1;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		ProcessKeyboard();
		ChangeStage();

		DWORD now = GetTickCount();
		deltaTime = now - frame_start;

		if (deltaTime >= tick_per_frame)
		{
			frame_start = now;
			UpdateWorld((float)tick_per_frame / 1000.0f);
			RenderFrame();
		}
	}
}

void Game::UpdateWorld(float delta)
{
	if (stage != NULL){
		stage->Update(delta);
	}
}

void Game::RenderFrame()
{
	if (stage!=NULL)
	{
		DxMngr::GetInstance().BeginRender();
		DxMngr::GetInstance().SetBackgroundColor(stage->backColor);
		stage->Render();
		DxMngr::GetInstance().EndRender();
	}
}

void Game::LoadResource()
{
	MyResources::GetInstance().LoadResources();
}

void Game::ProcessKeyboard()
{
	if (stage != NULL)
	{
		DiMngr::GetInstance().GetInputState();
		DiMngr::GetInstance().GetInputData();
		stage->ProcessKeyboard();
	}
}

void Game::ChangeStage()
{
	if (stage != NULL)
	{
		switch (stage->nextStage)
		{
		case GameStage::STAGE_GAMEPLAY:
			stage->Release();
			stage = new PlayStage("cutman.xml");
			break;

		case GameStage::STAGE_WELCOME:
			stage->Release();
			stage = new WelcomeStage();
			break;

		case GameStage::STAGE_INTRODUCE:
			stage->Release();
			stage = new IntroStage();
			break;

		case GameStage::STAGE_MAINMENU:
			stage->Release();
			stage = new MenuStage();
			break;
		}
	}
}

void Game::Release()
{
	if (stage != NULL){
		stage->Release();
	}
}