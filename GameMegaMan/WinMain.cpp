#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Game game(hInstance, "MegamanGame", VIEWPORT_WIDTH * WINDOWS_SCALE, VIEWPORT_HEIGHT * WINDOWS_SCALE, WINDOWS_FULLSCREEN, GAME_FRAME_RATE);
	
	if (game.Initialize())
	{
		game.Run();
	}
	else
	{
		MessageBox(NULL, "Init Fail!", "ERROR", MB_OK);
	}

	return 0;
}