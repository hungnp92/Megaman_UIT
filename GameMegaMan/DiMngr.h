#pragma once
#include <dinput.h>

#define KEYBOARD_BUFFER_SIZE 1024
#define KEYDOWN(name, key) (name[key] & 0x80) 

class DiMngr
{
public:
	DiMngr();
	~DiMngr();

	bool Initialize(HWND wndHandle);
	void Shutdown();
	void GetInputState();
	void GetInputData();
	bool IsKeyDown(int keyCode);
	
	char keyState[256];
	DIDEVICEOBJECTDATA KeyEvents[KEYBOARD_BUFFER_SIZE];
	DWORD dwElements;
	
	LPDIRECTINPUTDEVICE8 GetDevice();

	static DiMngr& GetInstance()
	{
		static DiMngr diMngr;
		return diMngr;
	}
private:
	LPDIRECTINPUT8 pDI; // The direct input object
	LPDIRECTINPUTDEVICE8 pDIDevice; // The direct input device
};
